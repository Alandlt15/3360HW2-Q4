#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

void generate_workload() {
	//utility setup
	cout << fixed << setprecision(3);
	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<double> uniform_dist(0.000001, 1.0);

	//variable declarations
	double arrival_lambda = 2.0;
	double service_mu = 1.0;
	double average_arrival = 0.0;
	double average_service = 0.0;
	double average_interarrival = 0.0;

	//performing CDF of Exponential to get arrival time and service times
	double u = uniform_dist(generator);
	double arrival_time = (-1.0 / arrival_lambda) * log(u);
	double service_time = (-1.0 / service_mu) * log(u);
	average_arrival += arrival_time;
	average_service += service_time;

	cout << "<" << 1 << ", " << arrival_time << ", " << service_time << ">" << endl;
	for (int i = 1; i < 1000; i++) {
		u = uniform_dist(generator);
		arrival_time += (-1.0 / arrival_lambda) * log(u);
		service_time = (-1.0 / service_mu) * log(u);
		average_arrival += arrival_time;
		average_service += service_time;
		cout << "<" << i + 1 << ", " << arrival_time << ", " << service_time << ">" << endl;
	}

	//calculating averages
	average_interarrival = arrival_time / (1000 - 1);
	average_arrival = 1 / average_interarrival;
	cout << "Average arrival rate: " << average_arrival << endl;
	cout << "Average service rate: " << average_service / 1000 << endl;
}

int main() {
	generate_workload();
	return 0;
}