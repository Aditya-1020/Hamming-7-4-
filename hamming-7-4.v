module hamming_encoder_decoder(
    input [3:0] data,          // 4-bit input data
    input [6:0] noisy_data,    // 7-bit noisy data
    output [6:0] encoded_data, // 7-bit encoded data
    output [6:0] corrected_data, // 7-bit corrected data
    output error_detected,     // Flag if error deteted
    output [2:0] syndrome
);
    // Internal signals
    reg [6:0] encoded;
    reg [6:0] corrected;
    reg [2:0] temp_arr;
    reg [2:0] check;
    reg [2:0] syndrome_value;

    // Hamming (7,4) encoding
    always @(*) begin
        encoded[2] = data[0];  // D1 → Position 3
        encoded[4] = data[1];  // D2 → Position 5
        encoded[5] = data[2];  // D3 → Position 6
        encoded[6] = data[3];  // D4 → Position 7

        // Parity Bits: P1, P2, P3
        encoded[0] = encoded[2] ^ encoded[4] ^ encoded[6];  // P1 → Position 1
        encoded[1] = encoded[2] ^ encoded[5] ^ encoded[6];  // P2 → Position 2
        encoded[3] = encoded[4] ^ encoded[5] ^ encoded[6];  // P3 → Position 4
    end

    assign encoded_data = encoded;

    // Syndrome Calculation (Error detection)
    always @(*) begin
        temp_arr[0] = noisy_data[2] ^ noisy_data[4] ^ noisy_data[6];  // P1 → Position 1
        temp_arr[1] = noisy_data[2] ^ noisy_data[5] ^ noisy_data[6];  // P2 → Position 2
        temp_arr[2] = noisy_data[4] ^ noisy_data[5] ^ noisy_data[6];  // P3 → Position 4

        check[0] = encoded[0];  // P1 from original encoded
        check[1] = encoded[1];  // P2 from original encoded
        check[2] = encoded[3];  // P3 from original encoded

        syndrome_value = 0;
        syndrome_value[0] = (temp_arr[0] != check[0]);
        syndrome_value[1] = (temp_arr[1] != check[1]);
        syndrome_value[2] = (temp_arr[2] != check[2]);

        syndrome = syndrome_value;
    end

    // Error correction
    always @(*) begin
        corrected = noisy_data;

        if (syndrome != 3'b000) begin
            // Error at position frm syndrome
            corrected[syndrome - 1] = ~corrected[syndrome - 1]; // Flip error bit
        end
    end

    // Error detection signal (indicates if an error was found)
    assign error_detected = (syndrome != 3'b000);

    assign corrected_data = corrected;

endmodule