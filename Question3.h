#include <iostream>
#include <cmath>

class FourVector{
	float energy;
	float momentumX;
	float momentumY;
	float momentumZ;

	public:
		FourVector();
		void SetFourVector(float e, float px, float py, float pz);
		void PrintVector();
		float GetMass();
		float GetEta();
		float GetMomentum();
		float DeltaEta(FourVector vectorToCompareWith);
		float GetParticleTrajectoryAngle();
		float DeltaPhi(FourVector vectorToCompareWith);
};