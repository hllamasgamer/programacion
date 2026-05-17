#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace poo {
    class Pokemon {
    public:
        Pokemon();
        ~Pokemon();

        // Getters y Setters para los 22 atributos
        void setNumber(int v) { m_number = v; }
        int getNumber() const { return m_number; }
        void setCode(int v) { m_code = v; }
        int getCode() const { return m_code; }
        void setSerial(int v) { m_serial = v; }
        int getSerial() const { return m_serial; }
        void setName(string v) { m_name = v; }
        string getName() const { return m_name; }
        void setType1(string v) { m_type1 = v; }
        string getType1() const { return m_type1; }
        void setType2(string v) { m_type2 = v; }
        string getType2() const { return m_type2; }
        void setColor(string v) { m_color = v; }
        string getColor() const { return m_color; }
        void setAbility1(string v) { m_ability1 = v; }
        string getAbility1() const { return m_ability1; }
        void setAbility2(string v) { m_ability2 = v; }
        string getAbility2() const { return m_ability2; }
        void setAbilityHidden(string v) { m_abilityHidden = v; }
        string getAbilityHidden() const { return m_abilityHidden; }
        void setGeneration(int v) { m_generation = v; }
        int getGeneration() const { return m_generation; }
        void setLegendary(int v) { m_legendary = v; }
        int getLegendary() const { return m_legendary; }
        void setMegaEvolution(int v) { m_megaEvolution = v; }
        int getMegaEvolution() const { return m_megaEvolution; }
        void setHeight(float v) { m_height = v; }
        float getHeight() const { return m_height; }
        void setWeight(float v) { m_weight = v; }
        float getWeight() const { return m_weight; }
        void setHp(int v) { m_hp = v; }
        int getHp() const { return m_hp; }
        void setAtk(int v) { m_atk = v; }
        int getAtk() const { return m_atk; }
        void setDef(int v) { m_def = v; }
        int getDef() const { return m_def; }
        void setSpAtk(int v) { m_spAtk = v; }
        int getSpAtk() const { return m_spAtk; }
        void setSpDef(int v) { m_spDef = v; }
        int getSpDef() const { return m_spDef; }
        void setSpd(int v) { m_spd = v; }
        int getSpd() const { return m_spd; }
        void setTotal(int v) { m_total = v; }
        int getTotal() const { return m_total; }

    private:
        int m_number, m_code, m_serial;
        string m_name, m_type1, m_type2, m_color, m_ability1, m_ability2, m_abilityHidden;
        int m_generation, m_legendary, m_megaEvolution;
        float m_height, m_weight;
        int m_hp, m_atk, m_def, m_spAtk, m_spDef, m_spd, m_total;
    };

    inline Pokemon::Pokemon() : m_number(0), m_code(0), m_serial(0), m_generation(0),
        m_legendary(0), m_megaEvolution(0), m_height(0.0f), m_weight(0.0f), m_hp(0),
        m_atk(0), m_def(0), m_spAtk(0), m_spDef(0), m_spd(0), m_total(0) {
    }
    inline Pokemon::~Pokemon() {}
}