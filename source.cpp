#include "header.h"
void Matrix_storage::print()
{
    for (int i{0}; i < N - 1; i++)
    {
        for (int j{0}; j < i + 1; j++)
            cout << A[i][j];
        cout << endl;
    }
}
int Matrix_storage::determine_country()
{
    int i, minimum = INT_MAX, price, min_top;
    for ( i = 0; i < N; i++)
    {
        price = BFS(i);
        if (minimum > price)
        {
            minimum = price;
            min_top = i;
        }
    }
    return min_top;
}
void Matrix_storage::read_struct(string name_of_file)
{
    int r;
    ifstream in(name_of_file);
    char ch;
    if (!in.is_open())
    {
        cout << "Ошибка открытия файла\n";
        return ;
    }
    in.get(ch);
    r = ch - 48;
    N = 0;
    while(r--)
    {
        in.get(ch);
        N *= 10;
        N += ch - 48;
    }
    in.get(ch);
    typeofr = ch - 48;
    allocate_struct();
    int  i = 0, j = 0, n = 1, tmp, z = 0, flag = 0, p = 0, k = 0;
    if (typeofr == 1)
        for (i = 0; i < N; i++)
        {
            in.get(ch);
            for (j = 0; j < N; j++)
            {
                in.get(ch);
                if (j < i && i != 0)
                {
                    A[i - 1][j] = ch - 48;
                }
            }
        }
    else
    {
        for (i = 0; i < N; i++)
        {
            in.get(ch);
            n = ch - 48;
            z = 0;
            p = i;
            for (k = 0; k < n; k++)
            {
                in.get(ch);
                r = ch - 48;
                tmp = 0;
                while(r--)
                {
                    in.get(ch);
                    tmp *= 10;
                    tmp += ch - 48;
                }
                for (z = 0; z < i; z++)
                {
                    if (tmp == z)
                    {
                        A[i - 1][z] = 1;
                    }
                }
                for (p = i; p < N - 1; p++)
                {
                    if ((tmp - 1) == p)
                    {
                        A[p][i] = 1;
                    }
                }
            }
        }
    }
}
Matrix_storage::~Matrix_storage()
{
    if (A)
    {
        for (int i{0}; i < N - 1; i++)
        {
            delete[] A[i];
        }
        delete[] A;
    }
}
Matrix_storage::Matrix_storage()
{
    A = nullptr;
    N = 0;
}
void Matrix_storage::allocate_struct()
{
    A = new(nothrow) int*[N - 1];
    if(A == nullptr)
    {
        cout << "Ошибка выделения памяти\n";
        return;
    }
    for (int i{0}; i < N - 1; i++)
    {
        A[i] = new(nothrow) int[i + 1];
        if(A[i] == nullptr)
        {
            cout << "Ошибка выделения памяти\n";
            return;
        }
    }
    for (int i{0}; i < N - 1; i++)
        for (int j{0}; j < i + 1; j++)
            A[i][j] = 0;
}
int Matrix_storage::next (int i, int cur)//функция получения индекса следующей после cur смежной вершины для вершины i
{
    int k, p;
    i--;
    if (cur < i + 1)
        cur++;
    for (p = cur; p < i + 1; p++)
    {
        if (cur == N - 1 || A[i][p])
        {
            if (cur < N - 1) return cur;
        }
        else cur++;
    }
    for( k = cur; k < N - 1; k++)
    {
        if (cur == N - 1 || A[k][i + 1])
        {
            if (cur < N - 1) return cur + 1;
        }
        else cur++;
    }
    return -1;				//если смежных больше нет, возвращаем признак отсутствия
}
int Matrix_storage::BFS(int a)
{
   int x, y, queue[N], beg = 0, end = -1, price = 0, dist[N], P[N];
   dist[a] = 0;
   for (int i{0}; i < N; i++)
   {
       if (i != a) dist[i] = INT_MAX;
       P[i] = 0;
   }
   queue[++end] = a;   /* помещаем вершину в очередь */
   P[a] = 1;    /* помечаем ее посещенной */
   while (beg <= end)      /* пока очередь не пустa */
   {
      x = queue[beg++];      /* берем элемент из очереди */
      y = -1;
      do
      {
         y = next (x, y); /* находим смежную с данной вершину */
         if (y != -1 && !P[y])   /* если есть смежная и она новая */
         {
            queue[++end] = y;       /* помещаем ее в очередь */
            P[y] = 1;               /* помечаем ее посещенной */
            dist[y] = dist[x] + 1;
         }
      }
      while (y != -1); /* пока не переберем все смежные с х вершины */
   }
   cout << "Растояние от " << a + 1 << endl;
   for (int i{0}; i < N; i++)
       cout << dist[i] << " ";
   cout << endl;
   for (x = 0; x < N; x++)
        price += dist[x];
   return price;
}
template <typename T>
void fill_data(string str, T &temp, function<bool(T&)> f)
{
    char c;
    cout << str;
    cin >> temp;
    if (!f(temp))
        cin.setstate(ios_base::failbit);
    while((c = getchar()) != '\n');
    while(cin.fail())
    {
        cin.clear();
        cout << str;
        cin >> temp;
        if (!f(temp))
            cin.setstate(ios_base::failbit);
        while((c = getchar()) != '\n');
    }
}
template void fill_data(string str, int &temp, function<bool(int&)> f);
template void fill_data(string str, char &temp, function<bool(char&)> f);
