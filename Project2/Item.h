#pragma once
#include <string>

class Char;

enum class TipoItem {
	Consumivel,
	Arma,
	Armadura
};

class Item {
protected:
    std::string nome;
    TipoItem tipo;

public:
    Item(std::string nome, TipoItem tipo);

    virtual int usar(Char& jogador) = 0;

    virtual bool consomeAoUsar() const = 0;

    virtual std::string getDescricao() const = 0;

    std::string getNome() const;
    TipoItem getTipo() const;

    virtual ~Item() = default;
};