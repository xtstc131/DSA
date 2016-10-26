#pragma once
#define N_CHAR (0x80 - 0x20)
struct HuffChar
{
	char ch; int weight;
	explicit HuffChar(char c = '^', int w = 0) : ch(c), weight(w) {}

	bool operator < (HuffChar const & hc) const
	{
		return weight < hc.weight;
	}
	bool operator <= (HuffChar const & hc) const
	{
		return weight <= hc.weight;
	}
	bool operator >= (HuffChar const & hc) const
	{
		return weight >= hc.weight;
	}
	bool operator > (HuffChar const & hc) const
	{
		return weight > hc.weight;
	}
	bool operator == (HuffChar const & hc) const
	{
		return weight == hc.weight;
	}
	friend	ostream & operator <<(ostream & out,const HuffChar & H) 
	{
		out <<H.ch<<" "<<H.weight<<"	";
		return out;
	}
};
