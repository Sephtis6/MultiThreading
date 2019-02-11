#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <stack>
#include <vector>
#include <functional> 
#include <condition_variable>
//namespaces used
using namespace std;
std::mutex mtx;

//variables used
string userName;
int a;
int b;

//first thread
void print_thread_id(int id) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	cout << "Thread #" << id << endl;
	mtx.unlock();
}

//second thread
void helloUser()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "Hello User." << endl;
}

//third thread
void getUserName()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "Please enter your name." << endl;
	cin >> userName;
}

//fourth thread
void welcomeUser()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "Welcome to the Multithread Assignment " << userName << "." << endl;
}

//fifth thread
void mathProblem()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "What is the answer to 12 * 12?" << endl;
	cin >> a;
	if (a < 143 | a > 145) {
		cout << "That is a wrong anser." << endl;
	}
	else if (a == 144)
	{
		cout << "That is correct." << endl;
	}
}

//sixth thread
void breakTime()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "Please take a small break from the quizes." << endl;
}

//seventh thread
void yearAsk()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "Waht is the year this program was made?" << endl;
	cin >> b;
	if (b == 2018) 
	{
		cout << "That is correct." << endl;
	}
	else if (b < 2017 | b > 2019)
	{
		cout << "That is incorrect." << endl;
	}
}

//eigth thread
void lastThoughts()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "This seems to be almost at it's end for the assignment needs." << endl;
}

//ninth thread
class background_task
{
public:
	void operator()() const
	{
		cout << "This thread was working in the background." << endl;
	}
};

//tenth thread
void goodByeUser()
{
	// this_thread::sleep_for(chrono::seconds(3));
	cout << "This is the end of the threads." << endl;
	cout << "Goobye " << userName << endl;
}

//main thread
void main() {
	int i = 0;

	//number of threads
	thread threads[10];
	// spawn 10 threads:
	//first thread
	if (i = 0) 
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
	}

	//for (auto& th : threads) th.join();
	//second thread
	if (i = 1) 
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread hi(helloUser);
		hi.join();
	}
	//third thread
	if (i = 2) 
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread name(getUserName);
		name.join();
	}
	//fourth thread
	if (i = 3)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread welcome(welcomeUser);
		welcome.join();
	}
	//fifth thread
	if (i = 4)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread mt(mathProblem);
		mt.join();
	}
	//sixth thread
	if (i = 5)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread bt(breakTime);
		bt.join();
	}
	//seventh thread
	if (i = 6)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread ya(yearAsk);
		ya.join();
	}
	//eigth thread
	if (i = 7)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread lt(lastThoughts);
		lt.join();
	}
	//ninth thread
	if (i = 8)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		background_task f;
		thread my_thread(f);
		my_thread.join();
	}
	//tenth thread
	if (i = 9)
	{
		threads[i] = thread(print_thread_id, i + 1);
		++i;
		thread gbu(goodByeUser);
		gbu.join();
	}

	if (i = 10) 
	{
		cout << "Main Thread has been completed." << endl;
	}

	//pauses system so you can read the prit out
	system("Pause");
	//closes the program
	exit(0);

}