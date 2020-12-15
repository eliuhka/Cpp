#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Toiduaine {
protected:
    string nimi;
    float valguprotsent{};
    float rasvaprotsent{};
    float sysivesikuteprotsen{};
public:
Toiduaine
(string name,
 float valgud,
 float rasvad,
 float sysivesikud)
 {
this->nimi = move(name);
this->valguprotsent = valgud;
this->rasvaprotsent = rasvad;
this->sysivesikuteprotsen = sysivesikud;
 }

    Toiduaine() = default;

    virtual double getvalguprotsent() {
        return valguprotsent;}
    virtual double getrasvaprotsent() {
        return rasvaprotsent;}
    virtual double getsysivesikuteprotsen() {
        return sysivesikuteprotsen;}
    string getNimetus() {
        return nimi;}
};

class komponent :
public Toiduaine {
private:
Toiduaine pt;
double kogus{};
public:
komponent() = default;

    explicit komponent(Toiduaine x) {
        this->pt = move(x);}
    komponent(Toiduaine x, float y) {
        this->pt = move(x);
        this->kogus = y;}
    Toiduaine getToiduaine() {
        return pt;}
    double getvalguprotsent() override {
        return kogus * pt.getvalguprotsent() / 100;}
    double getrasvaprotsent() override {
        return kogus * pt.getrasvaprotsent() / 100;}
    double getsysivesikuteprotsen() override {
        return kogus * pt.getsysivesikuteprotsen() / 100;}
    double getKogus() const {
        return kogus;}
};

class portsion : public komponent {
private:
vector<komponent> komponentideList;
public:
portsion() = default;

    explicit portsion(std::vector<komponent> listOfTK) {
        this->komponentideList = move(listOfTK);}
    double getkogumass() {
        float kogumass = 0;
        for (const komponent &a : komponentideList) {
        kogumass = kogumass + a.getKogus();}
        return kogumass;}
    double getKoguValguMass() {
        float valguMass = 0;
        for (komponent a : komponentideList) {
        valguMass = valguMass + a.getvalguprotsent();}
        return valguMass;}
    double getKoguRasvaMass() {
        float rasvaMass = 0;
        for (komponent a : komponentideList) {
        rasvaMass = rasvaMass + a.getrasvaprotsent();}
        return rasvaMass;}
    double getKogusysivesikuteMass() {
        float KogusysivesikuteMass = 0;
        for (komponent a : komponentideList) {
        KogusysivesikuteMass = KogusysivesikuteMass + a.getsysivesikuteprotsen();}
        return KogusysivesikuteMass;}
    float komponentidekogu(float PortsioniMass, Toiduaine ta) {
        float selleKomponendiMass = 0;
        for (komponent a : komponentideList) {
        if (ta.getNimetus() == a.getToiduaine().getNimetus()) {
        selleKomponendiMass = a.getKogus();}}
        float komponendisialdsusellesaine = selleKomponendiMass / getkogumass();
        return PortsioniMass * komponendisialdsusellesaine;}};

int main() {
    float porstsioni_suurus;
    Toiduaine kartul("kartul", 1.7, 0, 26);
    Toiduaine jogurt("jogurt", 55, 80, 15);
    Toiduaine oun("6un", 10, 0.5, 30);

    komponent koikKartul(kartul, 400);
    komponent koikJogurt(jogurt, 250);
    komponent koik6un(oun, 127);

    cout << "Kartuli kogumass on: " << koikKartul.getKogus() << "grammi" << endl;
    cout << "Valke on " << koikKartul.getvalguprotsent() << "g" << endl;
    cout << "Rasvu on " << koikKartul.getrasvaprotsent() << "g " << endl;
    cout << "Sysivesikuid on : " << koikKartul.getsysivesikuteprotsen() << "g " << endl;
    cout << "  " << endl;

    cout << "jogurti kogumass on: " << koikJogurt.getKogus() << " grammi" << endl;
    cout << "Valke on " << koikJogurt.getvalguprotsent() << " grammi" << endl;
    cout << "Rasvu on : " << koikJogurt.getrasvaprotsent() << " grammi" << endl;
    cout << "Sysivesikuid on  " << koikJogurt.getsysivesikuteprotsen() << " grammi" << endl;
    cout << " " << endl;

    cout << "6unte kogumass on: " << koik6un.getKogus() << " grammi" << endl;
    cout << "Valke on " << koik6un.getvalguprotsent() << " grammi " << endl;
    cout << "Rasvu on " << koik6un.getrasvaprotsent() << " grammi " << endl;
    cout << "Sysivesikuid on " << koik6un.getsysivesikuteprotsen() << " grammi " << endl;
    cout << " " << endl;

    vector<komponent> list = {koikKartul, koikJogurt, koik6un};

    portsion z(list);
    cout << "Portsiooni mass on: " << z.getkogumass() << " grammi" << endl;
    cout << "Portsiooni valgu sisaldus on: " << z.getKoguValguMass() << " grammi" << endl;
    cout << "Portsiooni rasva sisaldus on: " << z.getKoguRasvaMass() << " grammi" << endl;
    cout << "Portsiooni sysivesikute sisaldus on: " << z.getKogusysivesikuteMass() << "grammi" << endl;
    cout << "sisesta oma portsioni suurus grammides " << endl;
    cin >> porstsioni_suurus;
    cout << porstsioni_suurus << " grammise portsiooni jaoks on vaja " << z.komponentidekogu(porstsioni_suurus, jogurt) << " grammi " << jogurt.getNimetus() << "it "
    << z.komponentidekogu(porstsioni_suurus, kartul) << " grammi " << kartul.getNimetus() << "eid "
    << z.komponentidekogu(porstsioni_suurus, oun) << " grammi " << oun.getNimetus() << "u" << endl;
    return 0;
}
