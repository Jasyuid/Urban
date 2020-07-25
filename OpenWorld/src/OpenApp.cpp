#include <Urban.h>

class OpenWorld : public Urban::Application
{
public:
	OpenWorld()
	{

	}

	~OpenWorld()
	{

	}
};

Urban::Application* Urban::CreateApplication()
{
	return new OpenWorld();
}