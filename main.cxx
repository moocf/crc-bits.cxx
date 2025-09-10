#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;



// Compute remainder bits after division, which are the CRC bits.
inline vector<bool> computeRemainder(const vector<bool> &divd, const vector<bool> &divs) {
  int D = divd.size();
  int S = divs.size();
  int R = S - 1;
  int Q = D - R;
  vector<bool> tmp(divd), rem(R);
  // Perform polynomial division.
  for (int i=0; i<Q; i++) {
    if (!tmp[i]) continue;
    for (int j=0; j<S; j++)
      tmp[i+j] = tmp[i+j] != divs[j];
  }
  // Copy the remainder.
  copy(tmp.begin() + Q, tmp.end(), rem.begin());
  return rem;
}


// Corrupt bits with a given probability.
inline vector<bool> corruptBits(vector<bool> &bits, double prob) {
  int N = bits.size();
  vector<bool> corr(N);
  for (int i=0; i<N; i++) {
    double r = rand() / double(RAND_MAX);
    corr[i] = r < prob? !bits[i] : bits[i];
  }
  return corr;
}


// Parse a binary string into a vector of bits.
inline vector<bool> parseBits(const char *str) {
  int N = strlen(str);
  vector<bool> bits(N);
  for (int i=0; i<N; i++)
    bits[i] = (str[i] == '1');
  return bits;
}


// Convert a vector of bits back into a binary string.
inline void stringifyBits(char *buf, const vector<bool> &bits) {
  int N = bits.size();
  for (int i=0; i<N; i++)
    buf[i] = bits[i]? '1' : '0';
  buf[N] = '\0';
}


// Main function.
int main(int argc, char **argv) {
  srand(time(NULL));
  char buf[1024];
  // Accept message bits.
  vector<bool> msg;
  printf("Enter message bits to transmit (in binary): ");
  scanf_s("%s", buf, sizeof(buf));
  msg = parseBits(buf);
  int M = msg.size();
  if (M==0) { printf("ERROR: Message is empty\n"); return 1; }
  printf("Message length: %d bits\n", msg.size());
  // Accept generator polynomial bits.
  vector<bool> poly;
  printf("Enter generator polynomial (in binary): ");
  scanf_s("%s", buf, sizeof(buf));
  poly = parseBits(buf);
  int P = poly.size();
  if (P==0) { printf("ERROR: Generator polynomial is empty\n"); return 1; }
  if (!poly[0])     { printf("ERROR: Generator polynomial must start with 1\n"); return 1; }
  printf("Generator polynomial length: %d bits\n", poly.size());
  // Compute CRC bits.
  int C = P - 1;
  vector<bool> divd(M + C), crc;
  copy(msg.begin(), msg.end(), divd.begin());
  crc = computeRemainder(divd, poly);
  stringifyBits(buf, crc);
  printf("Computed CRC: %s\n", buf);
  printf("CRC length: %d bits\n", C);
  printf("\n");
  // Compute bits to be transmitted.
  vector<bool> trans(M + C);
  copy(msg.begin(), msg.end(), trans.begin());
  copy(crc.begin(), crc.end(), trans.begin() + M);
  stringifyBits(buf, trans);
  printf("Transmitted bits: %s\n", buf);
  printf("Transmitted length: %d bits\n", M + C);
  // Accept received bits.
  printf("Enter received bits: ");
  scanf_s("%s", buf, sizeof(buf));
  vector<bool> recv = parseBits(buf);
  printf("Received bits:    %s\n", buf);
  printf("Received length: %d bits\n", M + C);
  printf("\n");
  // Check for errors.
  vector<bool> rem = computeRemainder(recv, poly);
  stringifyBits(buf, rem);
  printf("CRC remainder: %s\n", buf);
  auto ft = [](bool v) { return v; };
  bool corrupted = any_of(rem.begin(), rem.end(), ft);
  if (corrupted) printf("CRC check failed, i.e., received bits are CORRUPTED!\n");
  else           printf("CRC check passed, i.e., received bits are not corrupted\n");
  return 0;
}
