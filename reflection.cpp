#include <meta>
#include <sstream>
#include <string>
#include <print>

template <typename T>
std::string to_string(const T &obj)
{
	constexpr auto ctx = std::meta::access_context::current();
	std::ostringstream os;
	os << std::meta::identifier_of(^^T) << " { ";
	bool first = true;
	template for (constexpr auto m :
				  [:std::meta::reflect_constant_array(
						std::meta::nonstatic_data_members_of(^^T, ctx)):])
	{
		if (!first)
			os << ", ";
		os << std::meta::identifier_of(m) << " = " << obj.[:m:];
		first = false;
	}
	os << " }";
	return os.str();
}

struct Point
{
	int x;
	int y;
};
struct Person
{
	std::string name;
	int age;
};

int main()
{
	std::println("{}", to_string(Point{3, 7}));
	std::println("{}", to_string(Person{"Alice", 30}));
	std::println("{}", to_string(Person{"Bob", 32}));
}