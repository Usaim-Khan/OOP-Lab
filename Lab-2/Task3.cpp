#include <iostream>
#include <string>
using namespace std;

class Calender{
    private:
        int CurrentYear;
        string Days[12][31];

    public:
        void setCurrentYear(int year){
            CurrentYear = year;
        }
        int getCurrentYear(){
            return CurrentYear;
        }

        void AddTask(string TaskDetails, int day, int month){
            Days[month-1][day-1] = TaskDetails;
        }

        void RemoveTask(int day, int month){
            Days[month-1][day-1] = "";
        }
        void ShowTasks(){
            for (int i = 0; i < 12; i++){
                for (int j = 0; j < 31; j++){
                    if (Days[i][j] != ""){
                        cout << " Task: " << Days[i][j] << endl;
                    }
                }
            }
        }
};

int main(){
    Calender myCalender;
    myCalender.setCurrentYear(2024);
    myCalender.AddTask("Doctor Appointment", 15, 3);
    myCalender.AddTask("Meeting with Team", 22, 3);
    myCalender.AddTask("Birthday Party", 5, 4);
    myCalender.AddTask("Conference", 12, 5);
    myCalender.AddTask("Vacation", 20, 6);
    myCalender.ShowTasks();
    myCalender.RemoveTask(15, 3);
    myCalender.RemoveTask(22, 3);
    cout << "---After removing a task---" << endl;
    myCalender.ShowTasks();
    return 0;
}