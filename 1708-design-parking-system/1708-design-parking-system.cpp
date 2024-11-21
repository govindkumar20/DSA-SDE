class ParkingSystem {
public:
    int b_car,s_car,m_car;

    ParkingSystem(int big, int medium, int small) {
        b_car=big;
        m_car=medium;
        s_car=small;
    
    }
    
    bool addCar(int carType) {
        
        if(carType==1 && b_car!=0){
            b_car--;
            return true;
        } 
        else if(carType==2 && m_car!=0){
            m_car--;
            return true;
        } 
        else if(carType==3 && s_car!=0){
            s_car--;
             return true;
        }
        return false; 
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */