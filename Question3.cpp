#include "Question3.h"


	FourVector::FourVector(){
		std::cout << "\nEnter energy of Four Vector: ";
		std::cin >> energy;

		std::cout << "Enter X component of momentum of Four Vector: ";
		std::cin >> momentumX;

		std::cout << "Enter Y component of momentum of Four Vector: ";
		std::cin >> momentumY;

		std::cout << "Enter Z component of momentum of Four Vector: ";
		std::cin >> momentumZ;
	}

	void FourVector::SetFourVector(float e, float px, float py, float pz){
		energy = e;
		momentumX = px;
		momentumY = py;
		momentumZ = pz;
	}

	float FourVector::GetMomentum(){
		float momentum = pow(momentumX,2) + pow(momentumY,2) + pow(momentumZ,2);
		return sqrt(momentum);
	}

	float FourVector::GetParticleTrajectoryAngle(){
		float theta = acos(momentumZ/GetMomentum());	
		
		return theta;	
	}

	float FourVector::GetMass(){
		float invariantMass = pow(energy,2) - pow(this->GetMomentum(),2);

		return invariantMass; 
	}

	float FourVector::DeltaEta(FourVector vectorToCompareWith){
		float delta = this->GetEta() - vectorToCompareWith.GetEta();
		return delta;
	}

	float FourVector::GetEta(){
		float Eta = tan(GetParticleTrajectoryAngle()/2);
		Eta = (log(Eta)/log(exp(1)));
		return Eta;
	}

	float FourVector::DeltaPhi(FourVector vectorToCompareWith){
		float deltaPhi = this->GetParticleTrajectoryAngle() - vectorToCompareWith.GetParticleTrajectoryAngle();
		return deltaPhi;
	}

	void FourVector::PrintVector(){
		std::cout << "\nMomentum: " << GetMomentum();
		std::cout << "\nEta: " << GetEta();
		std::cout << "\nMass: " << GetMass();
		std::cout << "\nPhi: " << GetParticleTrajectoryAngle();
	}

int main(){
	FourVector Vector1;

	FourVector Vector2;
	std::cout << "\nTesting SetFourVector method on vector2";

	float energy,momentumX,momentumY,momentumZ;

	std::cout << "\n\nEnter energy of Four Vector: ";
	std::cin >> energy;

	std::cout << "Enter X component of momentum of Four Vector: ";
	std::cin >> momentumX;

	std::cout << "Enter Y component of momentum of Four Vector: ";
	std::cin >> momentumY;

	std::cout << "Enter Z component of momentum of Four Vector: ";
	std::cin >> momentumZ;
	Vector2.SetFourVector(energy,momentumX,momentumY,momentumZ);

	std::cout << "\nVector 1: ";
	Vector1.PrintVector(); 

	std::cout << "\n\nVector 2: ";
	Vector2.PrintVector(); 

	std::cout << "\n\nDeltaPhi: " << Vector1.DeltaPhi(Vector2);
	std::cout << "\nDeltaEta: " << Vector1.DeltaEta(Vector2) << "\n";



}
