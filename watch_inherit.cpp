#include <iostream>
#include <string>


////////////////////////////////Base class Watch/////////////////////////////////
class Watch {

public:
    //Constructor
    Watch (std::string brand = "", int cost = 0): m_brand(brand), m_cost(cost) {

    }

    //Getters
    int getCost() const {return m_cost;}
    std::string getBrand() const {return m_brand;}

protected:
    std::string m_brand;
    int m_cost;
};


///////////////////////////Child class Digital_watch////////////////////////////
class Digital_watch : public Watch {

public:
    //Constructor
    Digital_watch (std::string brand, int cost, int bat_life = 0):
        Watch(brand, cost), m_bat_life(bat_life) {

    }

    //Friends
    friend std::ostream& operator<< (std::ostream &out, const Digital_watch &watch);

private:
    int m_bat_life; //время жизни батарейки (в годах)
};


////////////////////////////Child class Mech_watch//////////////////////////////
class Mech_watch : public Watch {

public:
    //Constructor
    Mech_watch (std::string brand, int cost, int power_reserve = 0):
        Watch(brand, cost), m_power_reserve(power_reserve) {

    }

    //Friends
    friend std::ostream& operator<< (std::ostream &out, const Mech_watch &watch);

private:
    int m_power_reserve; //запас хода (в часах)
};


/////////////////////////////Operators overload/////////////////////////////////
bool operator> (const Digital_watch &watch1, const Mech_watch &watch2) {

    return (watch1.getCost() > watch2.getCost());
}

bool operator> (const Mech_watch &watch1, const Digital_watch &watch2) {

    return (watch1.getCost() > watch2.getCost());
}

bool operator> (const Digital_watch &watch1, const Digital_watch &watch2) {

    return (watch1.getCost() > watch2.getCost());
}

bool operator> (const Mech_watch &watch1, const Mech_watch &watch2) {

    return (watch1.getCost() > watch2.getCost());
}


std::ostream& operator<< (std::ostream &out, const Digital_watch &watch) {

    out << "Brand: " << watch.getBrand()
        << ", cost: $" << watch.getCost()
        << ", battery life: " << watch.m_bat_life << " years" <<'\n';

    return out;
}

std::ostream& operator<< (std::ostream &out, const Mech_watch &watch) {

    out << "Brand: " << watch.getBrand()
        << ", cost: $" << watch.getCost()
        << ", power reserve: " << watch.m_power_reserve << " hours" <<'\n';

    return out;
}


///////////////////////////////////Main////////////////////////////////////////
int main() {

    Digital_watch citizen("citizen", 500, 10);
    Mech_watch omega("omega", 2000, 72);
    Mech_watch seiko("seiko", 1500, 60);
    Mech_watch tmp_mech ("", 0);

    std::cout << citizen;
    std::cout << omega;
    std::cout << seiko << '\n';

    tmp_mech = seiko > omega ? seiko : omega;

    if (tmp_mech > citizen) std::cout << "Most expensive watch is: " << tmp_mech;
    else std::cout << "Most expensive watch is: " << citizen;

return 0;
}
