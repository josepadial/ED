/**
  * @file cronologia.cpp
  * @brief Fichero implementacion del TDA Cronologia
  * @author Jose Antonio Padial Molina
  */

#include "cronologia.h"
#include "fechahistorica.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Cronologia::Cronologia() {
}

Cronologia::~Cronologia() {
}

Cronologia::Cronologia(const vector<FechaHistorica>& fechashistoricas) {
	setCronologia(fechashistoricas);
}

void Cronologia::setCronologia(const vector<FechaHistorica>& fechashistoricas) {
	this->fechaHisto = fechashistoricas;
}

void Cronologia::order() {
	for (int i = 0; i < this->fechaHisto.size() - 1; i++) {
		int minimo = i;
		for (int j = i + 1; j < this->fechaHisto.size(); j++)
			if (this->fechaHisto[j].getFecha() < this->fechaHisto[minimo].getFecha())
				minimo = j;
		swap(this->fechaHisto[i], this->fechaHisto[minimo]);
	}
}

int Cronologia::binarySearch(int fecha) {
	int middle;
	int bot = 0;
	int top = this->fechaHisto.size() - 1;
	bool found = false;

	while ((bot <= top) && !found) {
		middle = (bot + top) / 2;
		if (this->fechaHisto[middle].getFecha() == fecha)
			found = true;
		else if (this->fechaHisto[middle].getFecha() < fecha)
			bot = middle + 1;
		else
			top = middle - 1;
	}

	if (found)
		return middle;
	else
		return this->fechaHisto.size() - 1;
}

void Cronologia::swap(FechaHistorica& fch1, FechaHistorica& fch2) {
	FechaHistorica a = fch2;
	fch2 = fch1;
	fch1 = a;
}

Cronologia Cronologia::operator+(const Cronologia& crnlg) {
	Cronologia aux;
	for (int i = 0; i < this->fechaHisto.size(); i++)
		aux.fechaHisto.push_back(this->fechaHisto[i]);

	for (int i = 0; i < crnlg.fechaHisto.size(); i++)
		aux.addFechaHistorica(crnlg.fechaHisto[i]);

	int i = 0;
	while (i + 1 < this->fechaHisto.size()) {
		if (this->fechaHisto[i] == this->fechaHisto[i + 1]) {
			this->fechaHisto[i] = this->fechaHisto[i] + this->fechaHisto[i + 1];
			i--;
		}
		i++;
	}
	return aux;
}

vector<FechaHistorica> Cronologia::getFechashistoricas() {
	return this->fechaHisto;
}

void Cronologia::addFechaHistorica(FechaHistorica fchhst) {
	int pos = binarySearch(fchhst.getFecha());
	if (this->fechaHisto[pos].getFecha() == fchhst.getFecha())
		this->fechaHisto[pos] += fchhst;
	else {
		this->fechaHisto.push_back(fchhst);
		order();
	}
}

void Cronologia::setFechaHistorica(int fecha, const vector<string>& fechhistorcas) {
	this->fechaHisto[binarySearch(fecha)] = FechaHistorica(fecha, fechhistorcas);
}

void Cronologia::deleteFechaHistorica(int fecha) {
	for (int i = 0; i < this->fechaHisto.size(); i++)
		if (this->fechaHisto[i].getFecha() == fecha)
			this->fechaHisto.erase(this->fechaHisto.begin() + i);
}

bool Cronologia::isFechaHistorica(int fecha) {
	for (int i = 0; i < this->fechaHisto.size(); i++)
		if (this->fechaHisto[i].getFecha() == fecha)
			return true;
	return false;
}

FechaHistorica Cronologia::getFechaHistorica(int fecha) {
	for (int i = 0; i < this->fechaHisto.size(); i++)
		if (this->fechaHisto[i].getFecha() == fecha)
			return this->fechaHisto[i];

	// No se deberia llegar aqui
	return FechaHistorica();
}

ostream& operator<<(ostream& os, const Cronologia& crnlg) {
	for (int i = 0; i < crnlg.fechaHisto.size(); i++)
		os << crnlg.fechaHisto[i] << '\n';
	return os;
}

istream& operator >> (istream& is, Cronologia& crnlg) {
	if (is)
		while (is.peek() != '\0' && !is.eof()) {
			FechaHistorica fchhistorica;
			is >> fchhistorica;
			crnlg.fechaHisto.push_back(fchhistorica);
			crnlg.order();
		}
	return is;
}

void Cronologia::addAcontToFechaHistorica(int fecha, string acontecimiento) {
	FechaHistorica aux = getFechaHistorica(fecha);
	aux.insertarAcontecimiento(acontecimiento);
	setFechaHistorica(fecha, aux.getEventos());
}

bool Cronologia::operator==(const Cronologia & crnlg) {
	if (this->fechaHisto.size() != crnlg.fechaHisto.size()) return false;

	for (int i = 0; i < this->fechaHisto.size(); i++)
		if (this->fechaHisto[i] != crnlg.fechaHisto[i])
			return false;
	return true;
}

bool Cronologia::operator!=(const Cronologia & crnlg) {
	Cronologia aux = Cronologia(this->getFechashistoricas());

	return !(aux == crnlg);
}

void Cronologia::operator+=(const Cronologia crnlg) {
	Cronologia aux;
	for (int i = 0; i < this->fechaHisto.size(); i++)
		aux.fechaHisto.push_back(this->fechaHisto[i]);

	for (int i = 0; i < crnlg.fechaHisto.size(); i++)
		aux.addFechaHistorica(crnlg.fechaHisto[i]);

	int i = 0;
	while (i + 1 < this->fechaHisto.size()) {
		if (this->fechaHisto[i] == this->fechaHisto[i + 1]) {
			this->fechaHisto[i] = this->fechaHisto[i] + this->fechaHisto[i + 1];
			i--;
		}
		i++;
	}
	this->setCronologia(aux.getFechashistoricas());
}