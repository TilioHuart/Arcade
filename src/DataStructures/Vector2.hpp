//
// EPITECH PROJECT, 2025
// Vector2
// File description:
// Vector2
//

namespace anal {

    template <typename T>
    class Vector2 {
       public:
        Vector2() = delete;
        Vector2(T xValue, T yValue): _xValue(xValue), _yValue(yValue) {};
        T getX() { return this->_xValue;};
        T getY() { return this->_yValue;};

        void setX(T value) {this->_xValue = value;};
        void setY(T value) {this->_yValue = value;};

       private:
        T _xValue;
        T _yValue;
    };

}  // namespace anal
