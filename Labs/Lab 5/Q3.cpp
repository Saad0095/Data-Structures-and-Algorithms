#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Call {
public:
    int callID;
    int arrivalTime;
    string customerName;
    int processingTime;
    string status;

    Call(int id, int arrival, string name, int duration) {
        callID = id;
        arrivalTime = arrival;
        customerName = name;
        processingTime = duration;
        status = "Waiting";
    }
};

class CallCenter {
private:
    queue<Call> incomingCalls;
    int numCSRs;
    vector<bool> csrAvailable;
    vector<Call> activeCalls;
    vector<int> finishTime;

public:
    CallCenter(int numberOfCSRs)
        : numCSRs(numberOfCSRs),
          csrAvailable(numberOfCSRs, true),
          activeCalls(numberOfCSRs, Call(-1, 0, "", 0)),
          finishTime(numberOfCSRs, -1) {
    }

    void addCall(Call call) {
        incomingCalls.push(call);
        cout << "Call " << call.callID
             << " arrived: " << call.customerName << endl;
    }

    void processCalls(int currentTime) {
        for (int i = 0; i < numCSRs; i++) {
            if (!csrAvailable[i] &&
                finishTime[i] <= currentTime) {
                cout << "Time " << currentTime
                     << ": CSR " << i + 1
                     << " completed Call "
                     << activeCalls[i].callID << endl;

                csrAvailable[i] = true;
                finishTime[i] = -1;
            }
        }

        for (int i = 0; i < numCSRs; i++) {
            if (csrAvailable[i] && !incomingCalls.empty()) {
                Call call = incomingCalls.front();
                incomingCalls.pop();

                activeCalls[i] = call;
                activeCalls[i].status = "In Progress";
                csrAvailable[i] = false;
                finishTime[i] = currentTime + call.processingTime;

                cout << "Time " << currentTime
                     << ": CSR " << i + 1
                     << " assigned Call " << call.callID << endl;
            }
        }

        cout << "Waiting calls: "
             << incomingCalls.size() << "\n\n";
    }
};

int main() {
    CallCenter center(2);

    for (int time = 0; time <= 6; time++) {
        if (time == 0)
            center.addCall(Call(112, 0, "Abdullah", 4));

        if (time == 1)
            center.addCall(Call(113, 1, "Saad", 3));

        if (time == 2)
            center.addCall(Call(114, 2, "Ali", 2));

        if (time == 3)
            center.addCall(Call(115, 3, "Ahmed", 2));

        center.processCalls(time);
    }

    return 0;
}
