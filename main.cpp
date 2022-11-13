#include <iostream>
#include "Renderer.hpp"
using namespace std;
int main(){
	Renderer::SetMatrixSize(Position(40, 40));
	cout << GetLastError();
	Sleep(1000);
	return 0;
}