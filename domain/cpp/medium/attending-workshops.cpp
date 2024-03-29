#include<bits/stdc++.h>

using namespace std;
struct Workshop 
{
    int start_time;
    int duration;
    int end_time;
};

bool operator<(const Workshop & a, const Workshop & b)
{
    return (a.end_time < b.end_time);
}

struct Available_Workshops
{
    std::vector<Workshop> workshops_vector;
    int n;
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *obj;

    obj = new Available_Workshops;
    obj->n = n;
    for (int i = 0; i < n; i++){
        obj->workshops_vector.push_back((Workshop){start_time[i], duration[i], start_time[i] + duration[i]});
    }

    return (obj);
}

int CalculateMaxWorkshops(Available_Workshops *available_ptr)
{
    int curr_end;
    int max;

    sort(available_ptr->workshops_vector.begin(), available_ptr->workshops_vector.end());
    max = 0;
    curr_end = -1;
    for (long i = 0; i < available_ptr->n; i++)
    {
        if (curr_end <= available_ptr->workshops_vector[i].start_time)
        {
            curr_end = available_ptr->workshops_vector[i].end_time;
            max++;
        }
    }
    return (max);
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
