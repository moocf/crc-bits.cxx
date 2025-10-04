In this code, we will model the **end-to-end error detection process using CRC**:
Message → CRC Encoding → Transmission (with noise) → CRC Decoding → Error Detection.


### Problem statement

In digital communication systems, **error detection** is critical to ensure data integrity when messages are transmitted over unreliable channels. One of the most widely used techniques is the **Cyclic Redundancy Check (CRC)**, which appends a set of check bits (CRC bits) to the original message so that the receiver can detect whether errors occurred during transmission.

This problem involves **implementing and simulating CRC-based error detection** in C++. The program should:

1. **Accept a binary message** from the user (e.g., `"1101011011"`) representing the data bits to be transmitted. Use a function to convert the string to `vector<bool>` internally. Another function should convert the `vector<bool>` back to a binary string for display purposes.
2. **Accept a generator polynomial**, i.e., the divisor, (also in binary form, e.g., `"10011"`) used for CRC computation.
   * The generator polynomial must be non-empty and start with `1`.
3. **Compute the CRC bits** by performing polynomial division of the message (padded with zeros) by the generator polynomial. The remainder of this division forms the CRC.
4. **Append the CRC bits** to the message to create the transmitted codeword.
5. **Simulate transmission over a noisy channel** by flipping each transmitted bit with a user-defined probability (between `0.0` and `1.0`). This models random corruption in the channel.
6. **Display both transmitted and received bits** to allow comparison.
7. **Perform CRC error checking** at the receiver side by dividing the received bits with the generator polynomial.
   * If the remainder is **all zeros**, the data is considered error-free.
   * If the remainder contains **any nonzero bits**, an error has been detected.


### Inputs:

* Message bits (binary string, e.g., `"1101011011"`).
* Generator polynomial (binary string, e.g., `"10011"`).
* Bit corruption probability (floating-point number between 0.0 and 1.0).


### Outputs:

* Message length and generator polynomial length.
* Computed CRC bits.
* Transmitted codeword (message + CRC).
* Transmitted bits after corruption and received bits.
* CRC remainder at receiver side.
* Status of error detection (either *“CRC check passed”* or *“CRC check failed”*).
