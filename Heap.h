using namespace std;

class Heap
{
private:
    vector<int> data;
    int size;
    float time;

public:
    Heap();
    void Plot(int first, int second);
    void Delay();
    void Heapify();
};