#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class Queue
{
public:
    enum
    {
        QueueSize = 5
    };
    Queue()
    {
        front = 0;
        rear = 0;
    }
    bool push(char ch) //入队
    {
        if (full())
        {
            return false;
        }
        if (rear >= QueueSize)
        {
            rear = rear % QueueSize;
        }
        cout << "push " << ch << " in queue" << endl;
        array[rear++] = ch;
        return true;
    }
    bool pop(char &ch) // 出队
    {
        if (empty())
        {
            return false;
        }
        ch = first();
        front++;
        if (front >= QueueSize)
        {
            front = front % QueueSize;
        }
        return true;
    }
    char first() const //队头元素
    {
        return array[front];
    }
    char last() const //队尾元素
    {
        int t = rear;
        if (t == 0)
        {
            t = QueueSize;
        }
        return array[t - 1];
    }
    bool empty() const //判断队列是否为空
    {
        return rear == front;
    }
    bool full() const //判断队列是否为满
    {
        int t = rear;
        if (t < front)
        {
            t = t + QueueSize;
        }
        return (t - front) == QueueSize - 1;
    }
    void print() const //从队头开始输出所有元素
    {
        cout << "Queue content:";
        if (empty())
        {
            cout << "empty!" << endl;
            return;
        }
        for (int i = front;; i++)
        {
            if (i == rear)
            {
                break;
            }
            if (i >= QueueSize)
            {
                i = i % QueueSize;
            }
            cout << array[i] << " ";
        }
        cout << endl;
    }
private:
    int front;
    int rear;
    char array[QueueSize];
};
int main()
{
    Queue q;
    char ch;
    q.print();
    cout << "now, push A~E:" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (!q.push('A' + i))
            cout << "Queue is full, can't push !" << endl;
    }
    q.print();
    cout << "pop three characters:" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (!q.pop(ch))
        {
            cout << "Queue is empty,can't pop!" << endl;
        }
        else
            cout << "pop element:" << ch << endl;
    }
    q.print();
    cout << "first element:" << q.first() << ", last element:" << q.last() << endl;

    cout << "push 1~4:" << endl;

    for (int i = 0; i < 4; i++)
    {
        if (!q.push('1' + i))
            cout << "Queue is full, can't push !" << endl;
    }
    q.print();
    return 0;
}