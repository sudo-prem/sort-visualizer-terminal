using namespace std;

class Merge
{
private:
    vector<int> data;
    int size;
    float time;

public:
    Merge();
    void Plot(int first, int second);
    void Delay();
    void merge(int l, int mid, int h);
    void mergeSort();
};