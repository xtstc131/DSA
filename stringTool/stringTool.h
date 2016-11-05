#pragma once
#include <vector>
using namespace std;
namespace strTool
{
	inline int split(const std::string& str, std::vector<std::string>& ret_, std::string sep = ",")
	{
		if (str.empty())
			return 0;
		string tmp;
		auto pos_begin = str.find_first_not_of(sep);
		string::size_type sepLength = sep.length();
		string::size_type comma_pos;
		while (pos_begin != string::npos)
		{
			comma_pos = str.find(sep, pos_begin);//string substr (size_t pos = 0, size_t len = npos) const;
			if (comma_pos != string::npos)
			{
				tmp = str.substr(pos_begin, comma_pos - pos_begin);
				pos_begin = comma_pos + sepLength;
			}
			else
			{
				tmp = str.substr(pos_begin);
					pos_begin = comma_pos;
			}
			if (!tmp.empty())
			{
				ret_.push_back(tmp);
				tmp.clear();
			}
		}
		return 0;
	}


}
