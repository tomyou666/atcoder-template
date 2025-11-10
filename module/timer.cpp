
#include <bits/stdc++.h>
using namespace std;

class Timer
{
private:
  chrono::time_point<chrono::high_resolution_clock> start_time;
  chrono::time_point<chrono::high_resolution_clock> end_time;
  bool running;

public:
  Timer() : running(false) {}

  void start()
  {
    if (!running)
    {
      start_time = chrono::high_resolution_clock::now();
      running = true;
    }
  }

  void stop()
  {
    if (running)
    {
      end_time = chrono::high_resolution_clock::now();
      running = false;
      cout << "Elapsed time: " << elapsedMilliseconds() << " milliseconds" << endl;
    }
  }

  double elapsedMilliseconds()
  {
    return chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  }
};

int main()
{
  Timer timer;
  timer.start();
  timer.stop();
}
