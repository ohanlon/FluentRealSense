// FluentRealSenseConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cameras.h"
#include <iostream>
#include "glfw3.h"

int main()
{
	const auto devices = std::make_shared<cameras>();

	for (auto &dev : *devices)
	{
		cout << dev->get_information()->dump_diagnostic();
	}

  //glfwInit();
  //auto window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);

  return 0;
}

