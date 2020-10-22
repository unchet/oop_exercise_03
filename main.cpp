#include <iostream>
#include <vector>

class Figure{
	protected:
		double area;
		double x_centre, y_centre;
		std::vector <double> x;
		std::vector <double> y;
	public:
		virtual void calcCenter() = 0;
		virtual double calcArea() = 0;
		virtual void printCord() = 0;

		bool is_correct_coordinates(){
			for(int i = 0; i < x.size(); ++i){
				for(int j = i+1; j < x.size(); ++j){
					if(x[i] == x[j] && y[i] ==y[j]){
						std::cout << "Wrong coordinates!" << std::endl;
						return false;
					}
				}
			}
			return true;
		}

		void printCenter(){
			std::cout << "(" << x_centre << "," << y_centre << ")"<< std::endl;
		}

		Figure(){}

		virtual ~Figure(){}
};

class Hexagon: public Figure{
	public:
		Hexagon(){}

		Hexagon(double x1, double y1, double x2, double y2, double x3, double y3, 
				double x4, double y4, double x5, double y5, double x6, double y6){
			x.push_back(x1);
			x.push_back(x2);
			x.push_back(x3);
			x.push_back(x4);
			x.push_back(x5);
			x.push_back(x6);
			y.push_back(y1);
			y.push_back(y2);
			y.push_back(y3);
			y.push_back(y4);
			y.push_back(y5);
			y.push_back(y6);
		}

		~Hexagon(){}

		double calcArea()override{
			area = 0;
			for(int i = 0; i < x.size()-1; ++i){
				area += x[i]*y[i+1] - x[i+1]*y[i];
			}
			area += x[x.size()-1]*y[0] - y[x.size()-1]*x[0];
			area *= 0.5;
			if(area < 0)
				area *= -1;
			return area;
		}

		void calcCenter()override{
			x_centre = 0;
			y_centre = 0;
			for(int i = 0; i < x.size(); ++i){
				x_centre += x[i];
				y_centre += y[i];
			}
			x_centre /= x.size();
			y_centre /= y.size();
		}

		void printCord(){
			std::cout << "Hexagon coordinates:" << std::endl;
			for(int i = 0; i < x.size(); ++i){
				std::cout << "(" << x[i] << "," << y[i] << ")" << std::endl;
			}
		}
};

class Octagon: public Figure{
	public:
		Octagon(){}

		Octagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, 
				double x5, double y5, double x6, double y6, double x7, double y7, double x8, double y8){
			x.push_back(x1);
			x.push_back(x2);
			x.push_back(x3);
			x.push_back(x4);
			x.push_back(x5);
			x.push_back(x6);
			x.push_back(x7);
			x.push_back(x8);
			y.push_back(y1);
			y.push_back(y2);
			y.push_back(y3);
			y.push_back(y4);
			y.push_back(y5);
			y.push_back(y6);
			y.push_back(y7);
			y.push_back(y8);
		}

		~Octagon(){}

		double calcArea()override{
			area = 0;
			for(int i = 0; i < x.size()-1; ++i){
				area += x[i]*y[i+1] - x[i+1]*y[i];
			}
			area += x[x.size()-1]*y[0] - y[x.size()-1]*x[0];
			area *= 0.5;
			if(area < 0)
				area *= -1;
			return area;
		}

		void calcCenter()override{
			x_centre = 0;
			y_centre = 0;
			for(int i = 0; i < x.size(); ++i){
				x_centre += x[i];
				y_centre += y[i];
			}
			x_centre /= x.size();
			y_centre /= y.size();
		}

		void printCord(){
			std::cout << "Octagon coordinates:" << std::endl;
			for(int i = 0; i < x.size(); ++i){
				std::cout << "(" << x[i] << "," << y[i] << ")" << std::endl;
			}
		}
};	

class Triangle: public Figure{
	public:
		Triangle(){}

		Triangle(double x1, double y1, double x2, double y2, double x3, double y3){
			x.push_back(x1);
			x.push_back(x2);
			x.push_back(x3);
			y.push_back(y1);
			y.push_back(y2);
			y.push_back(y3);
		}

		~Triangle(){}

		double calcArea()override{
			area = 0;
			for(int i = 0; i < x.size()-1; ++i){
				area += x[i]*y[i+1] - x[i+1]*y[i];
			}
			area += x[x.size()-1]*y[0] - y[x.size()-1]*x[0];
			area *= 0.5;
			if(area < 0)
				area *= -1;
			return area;
		}

		void calcCenter()override{
			x_centre = 0;
			y_centre = 0;
			for(int i = 0; i < x.size(); ++i){
				x_centre += x[i];
				y_centre += y[i];
			}
			x_centre /= x.size();
			y_centre /= y.size();
		}

		void printCord(){
			std::cout << "Triangle coordinates:" << std::endl;
			for(int i = 0; i < x.size(); ++i){
				std::cout << "(" << x[i] << "," << y[i] << ")" << std::endl;
			}
		}
};

void printMenu(){
	std::cout << "\nCommands:" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "1. Add figure" << std::endl;
	std::cout << "2. Call the function for all figures" << std::endl;
	std::cout << "3. Delete figure by index" << std::endl;
	std::cout << "4. Print Menu" << std::endl;
}

int main(){
	int action, choice;
	std::vector<Figure*> v;
	printMenu();
	while(1){
		std::cout << "Choose number of menu: ";
		std::cin >> action;
		switch(action){
			case 0:
				for(int i = 0; i < v.size(); ++i){
					delete v[i];
				}
				return 0;
			case 1:
				double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
				std::cout << "\n1. Hexagon" << std::endl;
				std::cout << "2. Octagon" << std::endl;
				std::cout << "3. Triangle" << std::endl;
				std::cout << "Choose number:" << std::endl;
				std::cin >> choice;
				if(choice < 1 || choice > 3){
					std::cout << "Wrong number!" << std::endl;
					break;
				}
				Figure *figure;
				switch(choice){
					case 1:
						std::cout << "Write coordinates:" << std::endl;
						std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
						figure = new Hexagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6);
						break;
					case 2:
						std::cout << "Write coordinates:" << std::endl;
						std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7 >> x8 >> y8;
						figure = new Octagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8);
						break;
					case 3:
						std::cout << "Write coordinates:" << std::endl;
						std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
						figure = new Triangle(x1, y1, x2, y2, x3, y3);
						break;
				}
				if(!figure->is_correct_coordinates()){
					delete figure;
				}
				else{
					v.push_back(figure);
					std::cout << "Complete!" << std::endl;
				}
				break;
			case 2:
				std::cout << "\n1. Print coordinates" << std::endl;
				std::cout << "2. Calculate centre" << std::endl;
				std::cout << "3. Print centre" << std::endl;
				std::cout << "4. Calculate area" << std::endl;
				std::cout << "5. Calculate total area" << std::endl;
				std::cout << "Choose number:" << std::endl;
				std::cin >> choice;
				if(choice < 1 || choice > 6){
					std::cout << "Wrong number!" << std::endl;
					break;
				}
				switch(choice){
					case 1:
						for(int i = 0; i < v.size(); ++i){
							v[i]->printCord();
						}
						break;
					case 2:
						for(int i = 0; i < v.size(); ++i){
							v[i]->calcCenter();
						}
						break;
					case 3:
						for(int i = 0; i < v.size(); ++i){
							v[i]->printCenter();
						}
						break;
					case 4:
						for(int i = 0; i < v.size(); ++i){
							std::cout << "Area is " << v[i]->calcArea() << std::endl;
						}
						break;
					case 5:{
						double res = 0;
						for(int i = 0; i < v.size(); ++i){
							res += v[i]->calcArea();
						}
						std::cout << "Total area is " << res << std::endl;
						break;
					}
				}
				break;
			case 3:{
				int idx;
				
				std::cout << "Write index: ";
				std::cin >> idx;

				if(idx < 0 || idx > v.size()-1){
					std::cout << "Wrong index!" << std::endl;
					break;
				}
				v.erase(v.begin()+idx);
				std::vector<Figure*>(v).swap(v);
				std::cout << "Complete!" << std::endl;
				break;
			}
			case 4:
				printMenu();
				break;
			default:
				std::cout << "Wrong number! Try again" << std::endl; 
		}
	}
	
	v.clear();
				
	return 0;
}
