## Hamming (7,4) Code MVP Specifications

### 1. Hamming Codec
- **File**: `hamming_codec.vhd`
- **Entities**:
    - **Encoder**:
        - Input: 4-bit data.
        - Output: 7-bit Hamming code.
        - Functionality:
            - Assigns data bits to specific positions in the 7-bit output.
            - Calculates parity bits using XOR logic.
    - **Decoder**:
        - Input: 7-bit received Hamming code.
        - Output: Corrected 4-bit data and error syndrome (3-bit).
        - Functionality:
            - Recalculates parity bits and generates a syndrome.
            - Corrects single-bit errors based on the syndrome.

### 2. Testbench
- **File**: `hamming_tb.vhd`
- **Functionality**:
    - Instantiate encoder and decoder.
    - Test cases:
        - Valid transmission (no errors).
        - Single-bit error correction.
        - Double-bit error detection.
        - Simulated noise with random bit flips.
- Verify system behavior for error detection and correction.
