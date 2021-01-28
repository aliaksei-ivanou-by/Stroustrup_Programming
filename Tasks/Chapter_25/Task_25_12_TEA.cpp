#ifndef TASK_25_12_STDAFX_H
#include "Task_25_12_stdafx.h"
#include "Task_25_12_TEA.h"
#endif

void encipher(
	const unsigned long* const v,
	unsigned long* const w,
	const unsigned long* const k)
{
	static_assert(sizeof(long) == 4, "Wrong size of long for TEA");

	unsigned long y = v[0];
	unsigned long z = v[1];
	unsigned long sum = 0;
	const unsigned long delta = 0x9E3779B9;

	for (unsigned long n = 32; n-- > 0; )
	{
		y += (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
		sum += delta;
		z += (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
	}
	w[0] = y;
	w[1] = z;
}

void decipher(
	const unsigned long* const v,
	unsigned long* const w,
	const unsigned long* const k)
{
	static_assert(sizeof(long) == 4, "Wrong size of long for TEA");

	unsigned long y = v[0];
	unsigned long z = v[1];
	unsigned long sum = 0xC6EF3720;
	const unsigned long delta = 0x9E3779B9;

	for (unsigned long n = 32; n-- > 0; )
	{
		z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
		sum -= delta;
		y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
	}
	w[0] = y;
	w[1] = z;
}

void messageSent(
	const std::string& infile,
	const std::string& outfile,
	std::string& key)
{
	const int nchar = 2 * sizeof(long);
	const int kchar = 2 * nchar;

	while (key.size() < kchar)
	{
		key += '0';
	}

	std::ifstream inf(infile.c_str());
	std::ofstream outf(outfile.c_str());
	if (!inf || !outf)
	{
		throw std::runtime_error("Wrong file name");
	}

	const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());
	unsigned long outptr[2];
	char inbuf[nchar];
	unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf);
	int count = 0;

	while (inf.get(inbuf[count]))
	{
		outf << std::hex;
		if (++count == nchar)
		{
			encipher(inptr, outptr, k);
			outf << std::setw(8) << std::setfill('0') << outptr[0] << ' '
				<< std::setw(8) << std::setfill('0') << outptr[1] << ' ';
			count = 0;
		}
	}

	if (count)
	{
		while (count != nchar)
		{
			inbuf[count++] = '0';
			encipher(inptr, outptr, k);
			outf << outptr[0] << ' ' << outptr[1] << ' ';
		}
	}
}

void messageReceive(
	const std::string& infile,
	const std::string& outfile,
	std::string& key)
{
	const int nchar = 2 * sizeof(long);
	const int kchar = 2 * nchar;

	while (key.size() < kchar)
	{
		key += '0';
	}

	std::ifstream inf(infile.c_str());
	std::ofstream outf(outfile.c_str());
	if (!inf || !outf)
	{
		throw std::runtime_error("Wrong file name");
	}

	const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());
	unsigned long inptr[2];
	char outbuf[nchar + 1];
	outbuf[nchar] = 0;
	unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
	inf.setf(std::ios_base::hex, std::ios_base::basefield);

	while (inf >> inptr[0] >> inptr[1])
	{
		decipher(inptr, outptr, k);
		outf << outbuf;
	}
}