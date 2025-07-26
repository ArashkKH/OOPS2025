#if !defined(STATS__HPP)
#define STATS__HPP

#include <iostream>

using std::ostream;
using std::ios;

const int MAXITEMS = 10;
template <typename T>


class StatsBox {
    T m_values[MAXITEMS];
    int index = 0;
    public:
        void add(T value);
        T min() const;
        T max() const;
        void print(ostream& os = std::cout) const;
    
};


/* -------------------------------------------------------------------------- */
/*                               Implementation                               */
/* -------------------------------------------------------------------------- */


template<typename T>
void StatsBox<T>::add(T value){
    if(index < MAXITEMS){
        m_values[index] = value;
        index ++ ;
    }
}

template<typename T>
T StatsBox<T>::min() const{
    T min = m_values[0];
    for (size_t i = 1 ; i < index; i++)
    {

        if(!m_values){
            if(min){return min;}else{return 0;}
        }else if(m_values[i] < min){
            min = m_values[i];
        }
    }

    return min;
}

template<typename T>
T StatsBox<T>::max() const{
    T max = m_values[0];
    for (size_t i = 1 ; i < index; i++)
    {

        if(!m_values){
            if(max){return max;}else{return 0;}
        }else if(m_values[i] > max){
            max = m_values[i];
        }
    }

    return max;
}

template<typename T>
void StatsBox<T>::print(ostream& os) const{
    for (int i = 0; i < index; i++)
    {
        if(m_values[i]){
            os << '|';
            os.width(6);
            os.setf(ios::left);
            os << i;
        }
    }

    os << " |\n";
    os << "|";
    for (int i = 0; i < index; i++){
        os << "=======" ;
    }
    os << "|";

    os << "\n";
    
    for (int i = 0; i < index; i++)
    {
        if(m_values[i]){
            os << '|';
            os.width(6);
            os.setf(ios::left);
            os << m_values[i] ;
        }
    }
    
    os << " |" << std::endl;


    os << "\n\n";
    os << "Minimum of the values : " << min() << std::endl;
    os << "Maximum of the values : " << max() << std::endl;
}

#endif // STATS__HPP
