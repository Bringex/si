#include <iostream>
#include <vector>

using namespace std;

class Polynom{
public:
    vector<float> koef;
    Polynom(vector<float> _koef) : koef(_koef){
       // cout << "Created, deg is " << _koef.size() << "\n";
    };

    Polynom(const Polynom &poly) : koef(poly.koef){
        //cout << "Copied, deg is " << poly.koef.size() << "\n";
    };

    ~Polynom(){
        //cout << "Deleted\n";
    };

    Polynom operator=(const Polynom &poly){

        if (this == &poly)
            return *this;

        koef = poly.koef;
        return *this;
    };
    bool operator==(const Polynom& compPoly){
        int minD = min(koef.size(), compPoly.koef.size());

        for (int i = 0; i < minD; i++)
            if (koef[i] != compPoly.koef[i])
                return false;

        if (minD == koef.size())
            for (int i = minD; i < compPoly.koef.size(); i++)
                if (compPoly.koef[i] != 0)
                    return false;
        else
            for (int i = minD; i < koef.size(); i++)
                    if (koef[i] != 0)
                        return false;

        return true;
    };
    bool operator!=(const Polynom& compPoly){
        int minD = min(koef.size(), compPoly.koef.size());

        for (int i = 0; i < minD; i++)
            if (koef[i] != compPoly.koef[i])
                return true;

        if (minD == koef.size())
            for (int i = minD; i < compPoly.koef.size(); i++)
                if (compPoly.koef[i] != 0)
                    return true;
        else
            for (int i = minD; i < koef.size(); i++)
                    if (koef[i] != 0)
                        return true;

        return false;
    };

    Polynom operator-(){
        vector<float> newKoef (koef.size());

        for (int i = 0; i < koef.size(); i++)
            newKoef[i] = -koef[i];

        return Polynom(newKoef);
    }
    Polynom operator+(){
        return Polynom(koef);
    }

    friend Polynom operator-(const Polynom&, const Polynom&);
    friend Polynom operator+(const Polynom&, const Polynom&);
    friend Polynom operator*(const Polynom&, const Polynom&);
    friend Polynom operator/(const Polynom&, float);

    friend Polynom& operator+=(Polynom&, const Polynom&);
    friend Polynom& operator-=(Polynom&, const Polynom&);
    friend Polynom& operator*=(Polynom&, const Polynom&);
    friend Polynom& operator/=(Polynom&, float);

    friend ostream& operator<<(ostream &out, const Polynom&);
    friend istream& operator>>(istream &in, Polynom&);
    float& operator [] (const float index){
        return koef[index];
    }

    bool isNonZeros(){

        for (int i = 0; i < koef.size(); i++)
            if (koef[i] != 0)
                return true;
        return false;
    }
    string printPoly(){

        bool first = true;

        string str = "";
        cout.precision(2);
        if (!isNonZeros() && koef[0] == 0)
            str = "0";
        else
            for (int i = 0; i < koef.size(); i++)
                if (koef[i] > 0)
                    if (first){
                        str += precisionF(to_string(koef[i])) + "x^"
                            +  precisionF(to_string(koef.size() - i - 1)) + " ";

                        first = false;
                    }
                    else
                        str += "+ " + precisionF(to_string(koef[i]))
                            + "x^" +  precisionF(to_string(koef.size() - i - 1)) + " ";

                else if (koef[i] < 0)
                    if (first){
                        str += "- " + precisionF(to_string((-1)*koef[i])) + "x^"
                            +  precisionF(to_string(koef.size() - i - 1)) + " ";
                        first = false;
                    }
                    else
                        str += "- " + precisionF(to_string((-1)*koef[i])) + "x^"
                            +  precisionF(to_string(koef.size() - i - 1)) + " ";

        str += "\n";
        return str;
    }
    string precisionF(string str){
        return str.substr(0, str.find(".")+3);;
    }
};

Polynom operator-(const Polynom& left, const Polynom& right){
        unsigned int maxD = max(left.koef.size(), right.koef.size());
        vector<float> newKoef (maxD);


        if (left.koef.size() >= right.koef.size()){
            for (int i = 0; i < right.koef.size(); i++)
                newKoef[i] = left.koef[i] - right.koef[i];
            for (int i = right.koef.size(); i < maxD; i++)
                newKoef[i] = left.koef[i];

        }else{
            for (int i = 0; i < left.koef.size(); i++)
                newKoef[i] = left.koef[i] - right.koef[i];
            for (int i = left.koef.size(); i < maxD; i++)
                newKoef[i] = -right.koef[i];
        }

        return Polynom(newKoef);

    }
Polynom operator+(const Polynom& left, const Polynom& right){

    unsigned int maxD = max(left.koef.size(), right.koef.size());
    unsigned int minD = min(left.koef.size(), right.koef.size());
    vector<float> newKoef (maxD);

    for (int i = 0; i < minD; i++)
        newKoef[i] = left.koef[i] + right.koef[i];

    if (minD == left.koef.size())
        for (int i = minD; i < maxD; i++)
            newKoef[i] = right.koef[i];
    else
        for (int i = minD; i < left.koef.size(); i++)
            newKoef[i] = left.koef[i];

    return Polynom(newKoef);
}
Polynom operator*(const Polynom& left, const Polynom& right){
    unsigned int maxD = max(left.koef.size(), right.koef.size());
    unsigned int minD = min(left.koef.size(), right.koef.size());

    vector<float> newKoef (maxD + minD - 1, 0);


    for (int i = 0; i < left.koef.size(); i++)
        for (int j = 0; j < right.koef.size(); j++)
            newKoef[i + j] += left.koef[i] * right.koef[j];



    return Polynom(newKoef);
}
Polynom operator/(const Polynom& left, float num){
    vector<float> newKoef (left.koef.size());

    for (int i = 0; i < left.koef.size(); i++)
        newKoef[i] = left.koef[i] / num;

    return Polynom(newKoef);
}

Polynom& operator+=(Polynom& left, const Polynom& right){

    unsigned int maxD = max(left.koef.size(), right.koef.size());
    unsigned int minD = min(left.koef.size(), right.koef.size());
    vector<float> newKoef (maxD);

    for (int i = 0; i < minD; i++)
        left.koef[i] += right.koef[i];

    if (minD == left.koef.size())
        for (int i = minD; i < maxD; i++)
            left.koef[i] = right.koef[i];


    return left;
}
Polynom& operator-=(Polynom& left, const Polynom& right){

    unsigned int maxD = max(left.koef.size(), right.koef.size());
    unsigned int minD = min(left.koef.size(), right.koef.size());
    vector<float> newKoef (maxD);

    for (int i = 0; i < minD; i++)
        left.koef[i] -= right.koef[i];

    if (minD == left.koef.size())
        for (int i = minD; i < maxD; i++)
            left.koef[i] = right.koef[i];



    return left;
}
Polynom& operator*=(Polynom& left, const Polynom& right){

    unsigned int maxD = max(left.koef.size(), right.koef.size());
    unsigned int minD = min(left.koef.size(), right.koef.size());

    vector<float> newKoef (maxD + minD - 1, 0);

    for (int i = 0; i < left.koef.size(); i++)
        for (int j = 0; j < right.koef.size(); j++)
            newKoef[i + j] += left.koef[i] * right.koef[j];
    left.koef = newKoef;


    return left;
}
Polynom& operator/=(Polynom& left, float num){
    for (int i = 0; i < left.koef.size(); i++)
        left.koef[i] /= num;

    return left;
}

ostream& operator<<(ostream &out,  Polynom& poly){
    out << poly.printPoly();
    return out;
}
istream& operator>>(istream &in, Polynom& poly){
    vector<float> index;

    string str;
    getline(in, str);

    int found = 0;
    string newStr = "";
    while((found = str.find(" ")) != string::npos){
        newStr = str.substr(0, found);
        index.push_back(stof(newStr));
        str.erase(0, found + 1);
    }
    index.push_back(stof(str));

    poly.koef = index;
    return in;
}

int main()
{
    Polynom poly = Polynom({1, 2});
    Polynom poly3 = Polynom({1, -2});
    cout << poly;

    Polynom poly2 = Polynom({1, 0});
    cout << poly2;

    poly2 = -poly;
    cout << poly2;

    poly2 = poly + poly3 + poly;
    cout << poly2;

    poly2 += poly;
    cout << poly;

    poly *= poly3;
    poly /= 2.0f;

    cout << poly;
    cin >> poly;
    cout << poly;

    return 0;
}
