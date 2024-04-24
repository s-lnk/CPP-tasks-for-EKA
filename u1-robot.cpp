#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class ProximitySensor {
	string sn;
	bool state;

	public: ProximitySensor()  {
		//Default constructor
	}
		
	public: ProximitySensor(string _sn, bool _state)  {
		sn = _sn;
		state = _state;
	}
	
	public: State() {
		return state;
	}
	
	public: State(bool _state) {
		state = _state;
		return state;
	}
	
	public: Scan(int _area) {
		if (_area % 2 == 0) {
			return false;//even - unable to move
		} else {
			return true; //odd - can move
		}
		
	}
	
	public: PrintSensor() {
		cout << "Sensor " << sn << " state is " << state << "\n"; 
	}
};

class iRobot {
	string model;
	ProximitySensor sensor_left;
	ProximitySensor sensor_right;
	bool alarm;
	string map;
	
	public: iRobot(const string& _model, const ProximitySensor& _sensor_left, const ProximitySensor& _sensor_right) {
		model = _model;
		sensor_left = _sensor_left;
		sensor_right = _sensor_right;
		map = "";
		alarm = false;
		
	}
	public: Switch(bool _state) {
		sensor_left.State(_state);
		sensor_right.State(_state);
		if (_state) {
			cout << ".. robot " << model << " switched on\n"; 
		} else {
			cout << ".. robot " << model << " switched off\n";
		}
		
	}
	
	public: string GetAlarmStatus() {
		if (alarm) {
			return "red";
		} else {
			return "green";
		}
	}
	
	public: Run(int room[10]) {
		if (sensor_left.State() && sensor_right.State()) {
			cout << ".. robot " << model << " starts cleaning\n"; 
			for(int i=0;i<10;i++) {
				//cout << i;
				cout << ".. robot " << model << " makes move, received sensor raw data " << room[i] << ", left " << room[i] / 10 % 10 << ", right " << room[i] % 10 << " "; 
				if (sensor_left.Scan(room[i] / 10 % 10) && sensor_right.Scan(room[i] % 10)) {
					//Both directions are free - go forward
					map += "f";
					cout << "-> f";
				} else if(!sensor_left.Scan(room[i] / 10 % 10) && !sensor_right.Scan(room[i] % 10)) {
					//Both directions are blocked - alarm
					cout << "ALARM\n";
					alarm = true;
					break;
				} else if(sensor_left.Scan(room[i] / 10 % 10) && !sensor_right.Scan(room[i] % 10)) {
					//Left free - go left
					map += "l";
					cout << "-> l";
				} else if(!sensor_left.Scan(room[i] / 10 % 10) && sensor_right.Scan(room[i] % 10)) {
					//Right free - go right
					map += "r";
					cout << "-> r";
				}
				cout << "\n";
			}
			PrintRobot();
			
		} else {
			cout << ".. robot " << model << " cannot run as switched off\n"; 
		}
		
		
	}
	
	public: PrintRobot() {
		cout << "*****************************\n";
		cout << "iRobot " << model << " DIAGNOSTICS\n";
		cout << " Left ";
		sensor_left.PrintSensor();
		cout << " Right ";
		sensor_right.PrintSensor();
		cout << " Map: " << map << "\n";
		cout << " Status: " << GetAlarmStatus() << "\n";
		cout << "*****************************\n";
	} 
};

int main()
{
	int path[10] = { 10,11,49,13,14,15,16,17,21,19 };
	int path2[10] = { 10,11,49,13,14,15,16,17,22 };
	ProximitySensor s1 = ProximitySensor("123", false);
	ProximitySensor s2 = ProximitySensor("456", true);
	ProximitySensor s3 = ProximitySensor("789", true);
	ProximitySensor s4 = ProximitySensor("012", true);
	iRobot r1 = iRobot{"Xiaomi",s1, s2};
	iRobot r2 = iRobot{"Samsung",s3, s4};
	r1.Run(path);
	r1.Switch(true);
	r1.Run(path);
	r2.Switch(true);
	r2.Run(path2);
	cout << " ";
	system("pause");
    return 0;
}



