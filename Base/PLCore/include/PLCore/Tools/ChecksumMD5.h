/*********************************************************\
 *  File: ChecksumMD5.h                                  *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


#ifndef __PLCORE_CHECKSUMMD5_H__
#define __PLCORE_CHECKSUMMD5_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/Tools/Checksum.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    MD5 message-digest checksum
*
*  @remarks
*    --------------------------------------------------------------------------
*    Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
*    rights reserved.
*
*    License to copy and use this software is granted provided that it
*    is identified as the "RSA Data Security, Inc. MD5 Message-Digest
*    Algorithm" in all material mentioning or referencing this software
*    or this function.
*
*    License is also granted to make and use derivative works provided
*    that such works are identified as "derived from the RSA Data
*    Security, Inc. MD5 Message-Digest Algorithm" in all material
*    mentioning or referencing the derived work.
*
*    RSA Data Security, Inc. makes no representations concerning either
*    the merchantability of this software or the suitability of this
*    software for any particular purpose. It is provided "as is"
*    without express or implied warranty of any kind.
*
*    These notices must be retained in any copies of any part of this
*    documentation and/or software.
*    --------------------------------------------------------------------------
*    --------------------------------------------------------------------------
*    This implementation of the RSA MD5 Algorithm is basing on the implementation written
*    by Langfine Ltd (www.langfine.com).
*    The original code was just reorganized so fit's into PixelLight.
*
*    Author's Address
*    Ronald L. Rivest   Massachusetts Institute of Technology
*    Laboratory for Computer Science   NE43-324   545 Technology Square
*    Cambridge, MA  02139-1986   Phone: (617) 253-5880
*    EMail: rivest@theory.lcs.mit.edu
*
*    Langfine Ltd makes no representations concerning either
*    the merchantability of this software or the suitability of this
*    software for any particular purpose. It is provided "as is"
*    without express or implied warranty of any kind.
*
*    In addition to the above, Langfine make no warrant or assurances regarding the
*    accuracy of this implementation of the MD5 checksum algorithm nor any assurances
*    regarding its suitability for any purposes.
*    --------------------------------------------------------------------------
*    Below are extracts from a memo on The MD5 Message-Digest Algorithm by R. Rivest of MIT
*    Laboratory for Computer Science and RSA Data Security, Inc., April 1992.
*
*    1. Executive Summary
*    This document describes the MD5 message-digest algorithm. The
*    algorithm takes as input a message of arbitrary length and produces
*    as output a 128-bit "fingerprint" or "message digest" of the input.
*    It is conjectured that it is computationally infeasible to produce
*    two messages having the same message digest, or to produce any
*    message having a given prespecified target message digest. The MD5
*    algorithm is intended for digital signature applications, where a
*    large file must be "compressed" in a secure manner before being
*    encrypted with a private (secret) key under a public-key cryptosystem
*    such as RSA.
*
*    The MD5 algorithm is designed to be quite fast on 32-bit machines. In
*    addition, the MD5 algorithm does not require any large substitution
*    tables; the algorithm can be coded quite compactly.
*    The MD5 algorithm is an extension of the MD4 message-digest algorithm
*    1,2]. MD5 is slightly slower than MD4, but is more "conservative" in
*    design. MD5 was designed because it was felt that MD4 was perhaps
*    being adopted for use more quickly than justified by the existing
*    critical review; because MD4 was designed to be exceptionally fast,
*    it is "at the edge" in terms of risking successful cryptanalytic
*    attack. MD5 backs off a bit, giving up a little in speed for a much
*    greater likelihood of ultimate security. It incorporates some
*    suggestions made by various reviewers, and contains additional
*    optimizations. The MD5 algorithm is being placed in the public domain
*    for review and possible adoption as a standard.
*
*
*    2. Terminology and Notation
*    In this document a "word" is a 32-bit quantity and a "byte" is an
*    eight-bit quantity. A sequence of bits can be interpreted in a
*    natural manner as a sequence of bytes, where each consecutive group
*    of eight bits is interpreted as a byte with the high-order (most
*    significant) bit of each byte listed first. Similarly, a sequence of
*    bytes can be interpreted as a sequence of 32-bit words, where each
*    consecutive group of four bytes is interpreted as a word with the
*    low-order (least significant) byte given first.
*    Let x_i denote "x sub i". If the subscript is an expression, we
*    surround it in braces, as in x_{i+1}. Similarly, we use ^ for
*    superscripts (exponentiation), so that x^i denotes x to the i-th   power.
*    Let the symbol "+" denote addition of words (i.e., modulo-2^32
*    addition). Let X <<< s denote the 32-bit value obtained by circularly
*    shifting (rotating) X left by s bit positions. Let not(X) denote the
*    bit-wise complement of X, and let X v Y denote the bit-wise OR of X
*    and Y. Let X xor Y denote the bit-wise XOR of X and Y, and let XY
*    denote the bit-wise AND of X and Y.
*
*
*    3. MD5 Algorithm Description
*    We begin by supposing that we have a b-bit message as input, and that
*    we wish to find its message digest. Here b is an arbitrary
*    nonnegative integer; b may be zero, it need not be a multiple of
*    eight, and it may be arbitrarily large. We imagine the bits of the
*    message written down as follows:          m_0 m_1 ... m_{b-1}
*    The following five steps are performed to compute the message digest
*    of the message.
*
*    3.1 Step 1. Append Padding Bits
*    The message is "padded" (extended) so that its length (in bits) is
*    congruent to 448, modulo 512. That is, the message is extended so
*    that it is just 64 bits shy of being a multiple of 512 bits long.
*    Padding is always performed, even if the length of the message is
*    already congruent to 448, modulo 512.
*    Padding is performed as follows: a single "1" bit is appended to the
*    message, and then "0" bits are appended so that the length in bits of
*    the padded message becomes congruent to 448, modulo 512. In all, at
*    least one bit and at most 512 bits are appended.
*
*    3.2 Step 2. Append Length
*    A 64-bit representation of b (the length of the message before the
*    padding bits were added) is appended to the result of the previous
*    step. In the unlikely event that b is greater than 2^64, then only
*    the low-order 64 bits of b are used. (These bits are appended as two
*    32-bit words and appended low-order word first in accordance with the
*    previous conventions.)
*    At this point the resulting message (after padding with bits and with
*    b) has a length that is an exact multiple of 512 bits. Equivalently,
*    this message has a length that is an exact multiple of 16 (32-bit)
*    words. Let M[0 ... N-1] denote the words of the resulting message,
*    where N is a multiple of 16.
*
*    3.3 Step 3. Initialize MD Buffer
*    A four-word buffer (A,B,C,D) is used to compute the message digest.
*    Here each of A, B, C, D is a 32-bit register. These registers are
*    initialized to the following values in hexadecimal, low-order bytes   first):
*           word A: 01 23 45 67          word B: 89 ab cd ef
*           word C: fe dc ba 98          word D: 76 54 32 10
*
*    3.4 Step 4. Process Message in 16-Word Blocks
*    We first define four auxiliary functions that each take as input
*    three 32-bit words and produce as output one 32-bit word.
*           F(X,Y,Z) = XY v not(X) Z          G(X,Y,Z) = XZ v Y not(Z)
*           H(X,Y,Z) = X xor Y xor Z          I(X,Y,Z) = Y xor (X v not(Z))
*    In each bit position F acts as a conditional: if X then Y else Z.
*    The function F could have been defined using + instead of v since XY
*    and not(X)Z will never have 1's in the same bit position.) It is
*    interesting to note that if the bits of X, Y, and Z are independent
*    and unbiased, the each bit of F(X,Y,Z) will be independent and   unbiased.
*    The functions G, H, and I are similar to the function F, in that they
*    act in "bitwise parallel" to produce their output from the bits of X,
*    Y, and Z, in such a manner that if the corresponding bits of X, Y,
*    and Z are independent and unbiased, then each bit of G(X,Y,Z),
*    H(X,Y,Z), and I(X,Y,Z) will be independent and unbiased. Note that
*    the function H is the bit-wise "xor" or "parity" function of its   inputs.
*    This step uses a 64-element table T[1 ... 64] constructed from the
*    sine function. Let T[i] denote the i-th element of the table, which
*    is equal to the integer part of 4294967296 times abs(sin(i)), where i
*    is in radians. The elements of the table are given in the appendix.
*    Do the following:
*
*    // Process each 16-word block.
*    For i = 0 to N/16-1 do     // Copy block i into X.
*        For j = 0 to 15 do
*            Set X[j] to M[i*16+j]
*       end //of loop on j
*
*       // Save A as AA, B as BB, C as CC, and D as DD.
*       AA = A     BB = B
*       CC = C     DD = D
*
*       // Round 1.
*       // Let [abcd k s i] denote the operation
*       // a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s).
*       // Do the following 16 operations.
*       [ABCD  0  7  1]  [DABC  1 12  2]  [CDAB  2 17  3]  [BCDA  3 22  4]
*       [ABCD  4  7  5]  [DABC  5 12  6]  [CDAB  6 17  7]  [BCDA  7 22  8]
*       [ABCD  8  7  9]  [DABC  9 12 10]  [CDAB 10 17 11]  [BCDA 11 22 12]
*       [ABCD 12  7 13]  [DABC 13 12 14]  [CDAB 14 17 15]  [BCDA 15 22 16]
*
*       // Round 2.
*       // Let [abcd k s i] denote the operation 
*       // a = b + ((a + G(b,c,d) + X[k] + T[i]) <<< s).
*       // Do the following 16 operations.
*       [ABCD  1  5 17]  [DABC  6  9 18]  [CDAB 11 14 19]  [BCDA  0 20 20]
*       [ABCD  5  5 21]  [DABC 10  9 22]  [CDAB 15 14 23]  [BCDA  4 20 24]
*       [ABCD  9  5 25]  [DABC 14  9 26]  [CDAB  3 14 27]  [BCDA  8 20 28]
*       [ABCD 13  5 29]  [DABC  2  9 30]  [CDAB  7 14 31]  [BCDA 12 20 32]
*
*       // Round 3.
*       // Let [abcd k s t] denote the operation
*       // a = b + ((a + H(b,c,d) + X[k] + T[i]) <<< s).
*       // Do the following 16 operations.
*       [ABCD  5  4 33]  [DABC  8 11 34]  [CDAB 11 16 35]  [BCDA 14 23 36]
*       [ABCD  1  4 37]  [DABC  4 11 38]  [CDAB  7 16 39]  [BCDA 10 23 40]
*       [ABCD 13  4 41]  [DABC  0 11 42]  [CDAB  3 16 43]  [BCDA  6 23 44]
*       [ABCD  9  4 45]  [DABC 12 11 46]  [CDAB 15 16 47]  [BCDA  2 23 48]
*
*       // Round 4.
*       // Let [abcd k s t] denote the operation
*       // a = b + ((a + I(b,c,d) + X[k] + T[i]) <<< s).
*       // Do the following 16 operations.
*       [ABCD  0  6 49]  [DABC  7 10 50]  [CDAB 14 15 51]  [BCDA  5 21 52]
*       [ABCD 12  6 53]  [DABC  3 10 54]  [CDAB 10 15 55]  [BCDA  1 21 56]
*       [ABCD  8  6 57]  [DABC 15 10 58]  [CDAB  6 15 59]  [BCDA 13 21 60]
*       [ABCD  4  6 61]  [DABC 11 10 62]  [CDAB  2 15 63]  [BCDA  9 21 64]
*
*       // Then perform the following additions. (That is increment each
*       //   of the four registers by the value it had before this block
*       //   was started.)
*       A = A + AA     B = B + BB     C = C + CC  D = D + DD
*
*    end // of loop on i
*
*    3.5 Step 5. Output
*    The message digest produced as output is A, B, C, D. That is, we
*    begin with the low-order byte of A, and end with the high-order byte of D.
*    This completes the description of MD5.
*
*    Summary
*    The MD5 message-digest algorithm is simple to implement, and provides
*    a "fingerprint" or message digest of a message of arbitrary length.
*    It is conjectured that the difficulty of coming up with two messages
*    having the same message digest is on the order of 2^64 operations,
*    and that the difficulty of coming up with any message having a given
*    message digest is on the order of 2^128 operations. The MD5 algorithm
*    has been carefully scrutinized for weaknesses. It is, however, a
*    relatively new algorithm and further security analysis is of course
*    justified, as is the case with any new proposal of this sort.
*
*
*    5. Differences Between MD4 and MD5
*    The following are the differences between MD4 and MD5:
*        1.   A fourth round has been added.
*        2.   Each step now has a unique additive constant.
*        3.   The function g in round 2 was changed from (XY v XZ v YZ) to
*        (XZ v Y not(Z)) to make g less symmetric.
*        4.   Each step now adds in the result of the previous step.  This
*        promotes a faster "avalanche effect".
*        5.   The order in which input words are accessed in rounds 2 and
*        3 is changed, to make these patterns less like each other.
*        6.   The shift amounts in each round have been approximately
*        optimized, to yield a faster "avalanche effect." The shifts in
*        different rounds are distinct.
*
*    References
*    [1] Rivest, R., "The MD4 Message Digest Algorithm", RFC 1320, MIT and
*        RSA Data Security, Inc., April 1992.
*    [2] Rivest, R., "The MD4 message digest algorithm", in A.J.  Menezes
*        and S.A. Vanstone, editors, Advances in Cryptology - CRYPTO '90
*        Proceedings, pages 303-311, Springer-Verlag, 1991.
*    [3] CCITT Recommendation X.509 (1988), "The Directory -
*        Authentication Framework."APPENDIX A - Reference Implementation
*
*
*    The level of security discussed in this memo is considered to be
*    sufficient for implementing very high security hybrid digital-
*    signature schemes based on MD5 and a public-key cryptosystem.
*
*  @note
*    - MD5 produces a 128-bit/16-byte hash
*/
class ChecksumMD5 : public Checksum {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		PLCORE_API ChecksumMD5();

		/**
		*  @brief
		*    Destructor
		*/
		PLCORE_API virtual ~ChecksumMD5();


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Rotates the bits in a 32 bit uint32 left by a specified amount
		*
		*  @param[in] x
		*    The value to be rotated
		*  @param[in] n
		*    The number of bits to rotate by
		*
		*  @return
		*    The rotated uint32
		*/
		inline uint32 RotateLeft(uint32 x, int n) const;

		/**
		*  @brief
		*    Implementation of basic MD5 transformation algorithm
		*
		*  @param[in, out] nA
		*    Current (partial) checksum
		*  @param[in]      nB
		*    Current (partial) checksum
		*  @param[in]      nC
		*    Current (partial) checksum
		*  @param[in]      nD
		*    Current (partial) checksum
		*  @param[in]      nX
		*    Input data
		*  @param[in]      nS
		*    MD5_SXX Transformation constant
		*  @param[in]      nT
		*    MD5_TXX Transformation constant
		*/
		inline void FF(uint32 &nA, uint32 nB, uint32 nC, uint32 nD, uint32 nX, uint32 nS, uint32 nT) const;

		/**
		*  @brief
		*    Implementation of basic MD5 transformation algorithm
		*
		*  @param[in, out] nA
		*    Current (partial) checksum
		*  @param[in]      nB
		*    Current (partial) checksum
		*  @param[in]      nC
		*    Current (partial) checksum
		*  @param[in]      nD
		*    Current (partial) checksum
		*  @param[in]      nX
		*    Input data
		*  @param[in]      nS
		*    MD5_SXX Transformation constant
		*  @param[in]      nT
		*    MD5_TXX Transformation constant
		*/
		inline void GG(uint32 &nA, uint32 nB, uint32 nC, uint32 nD, uint32 nX, uint32 nS, uint32 nT) const;

		/**
		*  @brief
		*    Implementation of basic MD5 transformation algorithm
		*
		*  @param[in, out] nA
		*    Current (partial) checksum
		*  @param[in]      nB
		*    Current (partial) checksum
		*  @param[in]      nC
		*    Current (partial) checksum
		*  @param[in]      nD
		*    Current (partial) checksum
		*  @param[in]      nX
		*    Input data
		*  @param[in]      nS
		*    MD5_SXX Transformation constant
		*  @param[in]      nT
		*    MD5_TXX Transformation constant
		*/
		inline void HH(uint32 &nA, uint32 nB, uint32 nC, uint32 nD, uint32 nX, uint32 nS, uint32 nT) const;

		/**
		*  @brief
		*    Implementation of basic MD5 transformation algorithm
		*
		*  @param[in, out] nA
		*    Current (partial) checksum
		*  @param[in]      nB
		*    Current (partial) checksum
		*  @param[in]      nC
		*    Current (partial) checksum
		*  @param[in]      nD
		*    Current (partial) checksum
		*  @param[in]      nX
		*    Input data
		*  @param[in]      nS
		*    MD5_SXX Transformation constant
		*  @param[in]      nT
		*    MD5_TXX Transformation constant
		*/
		inline void II(uint32 &nA, uint32 nB, uint32 nC, uint32 nD, uint32 nX, uint32 nS, uint32 nT) const;

		/**
		*  @brief
		*    Transfers the data in an 8 bit array to a 32 bit array
		*
		*  @param[out] nOutput
		*    The 32 bit (uint32) destination array
		*  @param[in]  nInput
		*    The 8 bit (uint8) source array
		*  @param[in]  nLength
		*    The number of 8 bit data items in the source array
		*
		*  @remarks
		*    Four uint8 from the input array are transferred to each uint32 entry of the
		*    output array. The first uint8 is transferred to the bits (0-7)  of the output
		*    uint32, the second uint8 to bits 8-15 etc. The algorithm assumes that the
		*    input array is a multiple of 4 bytes long so that there is a perfect fit into
		*    the array of 32 bit words.
		*/
		inline void ByteToDWord(uint32 nOutput[], const uint8 nInput[], uint32 nLength) const;

		/**
		*  @brief
		*    Transfers the data in an 32 bit array to a 8 bit array
		*
		*  @param[out] nOutput
		*    The 8 bit destination array
		*  @param[in]  nInput
		*    The 32 bit source array
		*  @param[in]  nLength
		*    The number of 8 bit data items in the source array
		*
		*  @remarks
		*    One uint32 from the input array is transferred into four uint8 in the output
		*    array. The first (0-7) bits of the first uint32 are transferred to the first
		*    output uint8, bits bits 8-15 are transferred from the second uint8 etc.
		*    The algorithm assumes that the output array is a multiple of 4 bytes long
		*    so that there is a perfect fit of 8 bit uint8 into the 32 bit uint32.
		*/
		inline void DWordToByte(uint8 nOutput[], uint32 nInput[], uint32 nLength) const;

		/**
		*  @brief
		*    MD5 basic transformation algorithm; transforms 'm_nMD5'
		*
		*  @param[in] nBlock
		*    Block
		*
		*  @remarks
		*    An MD5 checksum is calculated by four rounds of 'Transformation'. The
		*    MD5 checksum currently held in m_nMD5 is merged by the transformation
		*    process with data passed in 'nBlock'.
		*/
		void Transform(const uint8 nBlock[64]);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		uint8  m_nBuffer[64];	/**< Input buffer */
		uint32 m_nCount[2];		/**< Number of bits, modulo 2^64 (lsb first) */
		uint32 m_nMD5[4];		/**< MD5 checksum */


	//[-------------------------------------------------------]
	//[ Private virtual Checksum functions                    ]
	//[-------------------------------------------------------]
	private:
		virtual void Update(const uint8 nInput[], uint32 nInputLen) override;
		virtual String Final() override;
		virtual void Reset() override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLCORE_CHECKSUMMD5_H__
