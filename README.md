Find CRC for message bits, corrupt some bits, and later validate them (CLI).

> See [PROBLEM](PROBLEM.md) for details on the problem statement. \
> Run this on: [OnlineGDB](https://onlinegdb.com/VJVsWtTv-)

<br>


```bash
$ clang main.cxx
$ ./a.out

# Enter message bits to transmit (in binary): 1101011011
# Message length: 10 bits
# Enter generator polynomial (in binary): 10011
# Generator polynomial length: 5 bits
# Computed CRC: 1110
# CRC length: 4 bits
#
# Transmitted bits: 11010110111110
# Transmitted length: 14 bits
# Enter received bits: 11010110011110
# Received bits:    11010110011110
# Received length: 14 bits
#
# CRC remainder: 0110
# CRC check failed, i.e., received bits are CORRUPTED!
```

<br>

```bash
$ clang main.cxx
$ ./a.out

# Enter message bits to transmit (in binary): 1101011011
# Message length: 10 bits
# Enter generator polynomial (in binary): 10011
# Generator polynomial length: 5 bits
# Computed CRC: 1110
# CRC length: 4 bits
#
# Transmitted bits: 11010110111110
# Transmitted length: 14 bits
# Enter received bits: 11010110111110
# Received bits:    11010110111110
# Received length: 14 bits
#
# CRC remainder: 0000
# CRC check passed, i.e., received bits are not corrupted
```

<br>
<br>


[![](https://raw.githubusercontent.com/qb40/designs/gh-pages/0/image/11.png)](https://wolfram77.github.io)<br>
[![ORG](https://img.shields.io/badge/org-moocf-green?logo=Org)](https://moocf.github.io)
![](https://ga-beacon.deno.dev/G-G1E8HNDZYY:v51jklKGTLmC3LAZ4rJbIQ/github.com/moocf/crc-bits.cxx)
