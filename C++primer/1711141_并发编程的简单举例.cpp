#include <iostream>
#include <thread>

using namespace std;

void hello(){
	cout << "Hello Concurrent World\n";
}


int main(){
	cout << "MainThread is : " << this_thread::get_id() << endl;
	thread t(hello);
	cout << "TaskThread is : " << t.get_id() << endl;
	cout << hex << t.get_id() << endl;
	t.join();
	return 0;
}


