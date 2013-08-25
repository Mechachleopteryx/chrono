#ifndef CHCONSTRAINT_BILATERAL_H
#define CHCONSTRAINT_BILATERAL_H

#include "ChBaseGPU.h"

namespace chrono {
class ChApiGPU ChConstraintBilateral: public ChBaseGPU {
	public:
		ChConstraintBilateral(ChGPUDataManager *data_container_) {
			data_container = data_container_;
			Initialize();
		}
		~ChConstraintBilateral() {
		}

		void Project(custom_vector<real> & gamma);

		void host_RHS(int2 *ids, real *bi, bool * active, real3 *vel, real3 *omega, real3 *JXYZA, real3 *JXYZB, real3 *JUVWA, real3 *JUVWB, real *rhs);
		void ComputeRHS();

		void ComputeJacobians();

		void host_shurA(
				int2 *ids,
				bool *active,
				real *inv_mass,
				real3 *inv_inertia,
				real3 *JXYZA,
				real3 *JXYZB,
				real3 *JUVWA,
				real3 *JUVWB,
				real *gamma,
				real3 *updateV,
				real3 *updateO,
				real3* QXYZ,
				real3* QUVW,
				uint* offset);
		void host_shurB(
				int2 *ids,
				bool *active,
				real *inv_mass,
				real3 *inv_inertia,
				real * gamma,
				real3 *JXYZA,
				real3 *JXYZB,
				real3 *JUVWA,
				real3 *JUVWB,
				real3 *QXYZ,
				real3 *QUVW,
				real *AX);

		void ShurA(custom_vector<real> &x);
		void ShurB(custom_vector<real> &x, custom_vector<real> & output);
		void ShurBilaterals(custom_vector<real> &x_t, custom_vector<real> & AX);
		protected:
		custom_vector<real> rhs;

	}
	;}

#endif
