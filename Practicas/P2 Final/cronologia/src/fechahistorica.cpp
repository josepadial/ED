/**
  * @file fechahistorica.cpp
  * @brief Fichero implementacion del TDA FechaHistorica
  * @author Jose Antonio Padial Molina
  */

#include "fechahistorica.h"

FechaHistorica::FechaHistorica(){
	this -> fecha = 0;
}

FechaHistorica::FechaHistorica(int fecha){
	this -> fecha = fecha;
}

FechaHistorica::FechaHistorica(int fecha, const vector<string>& aconts){
	this -> fecha = fecha;
	this -> acontecimientos = aconts;
}

FechaHistorica::FechaHistorica(const FechaHistorica &otra){
	this -> fecha = otra.fecha;
	this -> acontecimientos = otra.acontecimientos;
}

FechaHistorica::~FechaHistorica(){

}

int FechaHistorica::getFecha() const{
	return this -> fecha;
}

int FechaHistorica::getFecha(){
	return this -> fecha;
}

string FechaHistorica::getEvento(int pos) const{
	return this -> acontecimientos[pos];
}

string FechaHistorica::getEvento(int pos){
	return this -> acontecimientos.at(pos);
}

vector<string> FechaHistorica::getEventos(){
	return this -> acontecimientos;
}

void FechaHistorica::setFecha(int fecha){
	this -> fecha = fecha;
}

void FechaHistorica::setAcontecimientos(const vector<string> aconts){
	this -> acontecimientos = aconts;
}

void FechaHistorica::insertarAcontecimiento(string evento){
	this -> acontecimientos.push_back(evento);
}

void FechaHistorica::deleteAcontecimiento(const string& acont){
	for(int i=0; i<this -> acontecimientos.size(); i++)
		if(this -> acontecimientos[i] == acont)
			deleteAcontecimiento(i);
}

void FechaHistorica::deleteAcontecimiento(int pos) {
	acontecimientos.erase(acontecimientos.begin() + pos);
}

int FechaHistorica::numeroDeAcontecimientos() const{
	return this -> acontecimientos.size();
}

int FechaHistorica::numeroDeAcontecimientos(){
	return this -> acontecimientos.size();
}

bool FechaHistorica::esAcontecimiento(string acont){
	for(int i=0; i< this -> acontecimientos.size(); i++)
		if(this -> acontecimientos[i] == acont)
			return true;
	return false;
}

void FechaHistorica::asignar(int fecha, vector<string> aconts){
	this->fecha = fecha;
	this->acontecimientos = aconts;
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica& fechaHst){
	this->fecha = fechaHst.fecha;
	this->acontecimientos = fechaHst.acontecimientos;

	return *this;
}

bool FechaHistorica::comparar(FechaHistorica fecha) {
	return (this->fecha == fecha.fecha);
}

void FechaHistorica::print() {
	cout << this->fecha;

	for (int i = 0; i < this->acontecimientos.size(); i++)
		cout << ("#" + this->acontecimientos[i]);

	cout << endl;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica& fechahst){
	FechaHistorica aux;
	if (fecha == fechahst.getFecha()){
		for (int i = 0; i < acontecimientos.size(); i++)
			aux.insertarAcontecimiento(acontecimientos[i]);
		for (int i = 0; i < fechahst.numeroDeAcontecimientos(); i++)
			aux.insertarAcontecimiento(fechahst.getEvento(i));
		aux.setFecha(fecha);
	}
	return aux;
}

void FechaHistorica::operator += (const FechaHistorica fechahst){
	if (this->fecha == fechahst.fecha)
		for (int i = 0; i < fechahst.acontecimientos.size(); i++)
			this->acontecimientos.push_back(fechahst.acontecimientos[i]);
}

bool FechaHistorica::operator== (const FechaHistorica & fchhst) {
	if (this->fecha != fchhst.fecha) return false;
	if (this->acontecimientos.size() != fchhst.acontecimientos.size()) return false;

	for (int i = 0; i < this->acontecimientos.size(); i++)
		if (this->acontecimientos[i] != fchhst.acontecimientos[i])
			return false;
		
	return true;
}


bool FechaHistorica::operator!= (const FechaHistorica & fchhst) {
	FechaHistorica aux = FechaHistorica(this->getFecha(), this->getEventos());
	
	return !(aux == fchhst);
}

ostream& operator<< (ostream & os, const FechaHistorica & fchhst) {
	string fchaconts;
	fchaconts = to_string(fchhst.fecha);

	for (int i = 0; i < fchhst.acontecimientos.size(); i++)
		fchaconts += ("#" + fchhst.acontecimientos[i]);

	fchaconts += '\n';
	return os << fchaconts;
}

istream& operator >> (istream& is, FechaHistorica& fchhst) {
	string aux;
	vector<string> acontecimientosLeidos = {};

	getline(is, aux, '#');

	fchhst.fecha = stoi(aux);

	getline(is, aux);
	istringstream ss(aux);

	while (getline(ss, aux, '#'))
		acontecimientosLeidos.push_back(aux);
	fchhst.acontecimientos = acontecimientosLeidos;

	return is;
}

bool FechaHistorica::operator<(const FechaHistorica& fchhst) {
	return (this->fecha < fchhst.fecha);
}

bool FechaHistorica::operator>(const FechaHistorica& fchhst) {
	return (this->fecha > fchhst.fecha);
}
