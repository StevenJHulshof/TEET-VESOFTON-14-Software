/*******************************************************************************
 * Begin of file sin_LUT.c
 *
 * @author: Lukas ten Hove
 * Created: 18/05/2016
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Lookup table for sin(0->360).
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sin_LUT.h"

	float const sin_LUT[360] =
	{
			0, 0.01745240643728351, 0.03489949670250097, 0.052335956242943835, 0.0697564737441253, 0.08715574274765817,
			0.10452846326765347, 0.12186934340514748, 0.13917310096006544, 0.15643446504023087, 0.17364817766693033,
			0.1908089953765448, 0.20791169081775934, 0.224951054343865, 0.24192189559966773, 0.25881904510252074,
			0.27563735581699916, 0.29237170472273677, 0.3090169943749474, 0.3255681544571567, 0.3420201433256687,
			0.35836794954530027, 0.374606593415912, 0.39073112848927377, 0.4067366430758002, 0.42261826174069944,
			0.4383711467890774, 0.45399049973954675, 0.4694715627858908, 0.48480962024633706, 0.49999999999999994,
			0.5150380749100542, 0.5299192642332049, 0.5446390350150271, 0.5591929034707469, 0.573576436351046,
			0.5877852522924731, 0.6018150231520483, 0.6156614753256583, 0.6293203910498374, 0.6427876096865393,
			0.6560590289905073, 0.6691306063588582, 0.6819983600624985, 0.6946583704589973, 0.7071067811865475,
			0.7193398003386511, 0.7313537016191705, 0.7431448254773942, 0.754709580222772, 0.766044443118978,
			0.7771459614569709, 0.788010753606722, 0.7986355100472928, 0.8090169943749475, 0.8191520442889918,
			0.8290375725550417, 0.838670567945424, 0.8480480961564261, 0.8571673007021123, 0.8660254037844386,
			0.8746197071393957, 0.8829475928589269, 0.8910065241883678, 0.898794046299167, 0.9063077870366499,
			0.9135454576426009, 0.9205048534524404, 0.9271838545667874, 0.9335804264972017, 0.9396926207859083,
			0.9455185755993167, 0.9510565162951535, 0.9563047559630354, 0.9612616959383189, 0.9659258262890683,
			0.9702957262759965, 0.9743700647852352, 0.9781476007338056, 0.981627183447664, 0.984807753012208,
			0.9876883405951378, 0.9902680687415704, 0.992546151641322, 0.9945218953682733, 0.9961946980917455,
			0.9975640502598242, 0.9986295347545738, 0.9993908270190958, 0.9998476951563913, 1, 0.9998476951563913,
			0.9993908270190958, 0.9986295347545738, 0.9975640502598242, 0.9961946980917455, 0.9945218953682733,
			0.9925461516413221, 0.9902680687415704, 0.9876883405951378, 0.984807753012208, 0.981627183447664,
			0.9781476007338057, 0.9743700647852352, 0.9702957262759965, 0.9659258262890683, 0.9612616959383189,
			0.9563047559630355, 0.9510565162951536, 0.9455185755993168, 0.9396926207859084, 0.9335804264972017,
			0.9271838545667874, 0.9205048534524403, 0.9135454576426009, 0.90630778703665, 0.8987940462991669,
			0.8910065241883679, 0.8829475928589269, 0.8746197071393959, 0.8660254037844387, 0.8571673007021123,
			0.8480480961564261, 0.838670567945424, 0.8290375725550417, 0.8191520442889917, 0.8090169943749475,
			0.7986355100472927, 0.788010753606722, 0.777145961456971, 0.766044443118978, 0.7547095802227721,
			0.7431448254773942, 0.7313537016191706, 0.7193398003386511, 0.7071067811865476, 0.6946583704589971,
			0.6819983600624986, 0.6691306063588583, 0.6560590289905073, 0.6427876096865395, 0.6293203910498374,
			0.6156614753256584, 0.6018150231520482, 0.5877852522924732, 0.5735764363510459, 0.5591929034707469,
			0.5446390350150273, 0.5299192642332049, 0.5150380749100544, 0.49999999999999994, 0.48480962024633717,
			0.4694715627858907, 0.45399049973954686, 0.4383711467890773, 0.4226182617406995, 0.40673664307580043,
			0.39073112848927377, 0.37460659341591224, 0.3583679495453002, 0.3420201433256689, 0.3255681544571566,
			0.3090169943749475, 0.2923717047227366, 0.2756373558169992, 0.258819045102521, 0.24192189559966773,
			0.2249510543438652, 0.20791169081775931, 0.19080899537654497, 0.17364817766693028, 0.15643446504023098,
			0.13917310096006533, 0.12186934340514755, 0.10452846326765373, 0.0871557427476582, 0.06975647374412552,
			0.05233595624294381, 0.03489949670250114, 0.01745240643728344, 1.2246467991473532e-16, -0.017452406437283637,
			-0.0348994967025009, -0.052335956242943564, -0.06975647374412527, -0.08715574274765794, -0.1045284632676535,
			-0.12186934340514731, -0.13917310096006552, -0.15643446504023073, -0.17364817766693047, -0.19080899537654472,
			-0.2079116908177595, -0.22495105434386498, -0.2419218955996675, -0.2588190451025208, -0.275637355816999,
			-0.29237170472273677, -0.3090169943749473, -0.32556815445715676, -0.34202014332566866, -0.35836794954530043,
			-0.374606593415912, -0.39073112848927355, -0.4067366430758002, -0.4226182617406993, -0.43837114678907746,
			-0.4539904997395467, -0.46947156278589086, -0.48480962024633695, -0.5000000000000001, -0.5150380749100542,
			-0.5299192642332048, -0.5446390350150271, -0.5591929034707467, -0.5735764363510462, -0.587785252292473,
			-0.6018150231520484, -0.6156614753256582, -0.6293203910498376, -0.6427876096865393, -0.656059028990507,
			-0.6691306063588582, -0.6819983600624984, -0.6946583704589974, -0.7071067811865475, -0.7193398003386512,
			-0.7313537016191705, -0.7431448254773944, -0.7547095802227719, -0.7660444431189779, -0.7771459614569706,
			-0.7880107536067221, -0.7986355100472928, -0.8090169943749473, -0.8191520442889916, -0.8290375725550418,
			-0.838670567945424, -0.8480480961564258, -0.8571673007021121, -0.8660254037844384, -0.8746197071393959,
			-0.882947592858927, -0.8910065241883678, -0.8987940462991668, -0.90630778703665, -0.913545457642601,
			-0.9205048534524403, -0.9271838545667873, -0.9335804264972016, -0.9396926207859084, -0.9455185755993168,
			-0.9510565162951535, -0.9563047559630353, -0.9612616959383189, -0.9659258262890683, -0.9702957262759965,
			-0.9743700647852351, -0.9781476007338056, -0.981627183447664, -0.984807753012208, -0.9876883405951377,
			-0.9902680687415703, -0.9925461516413221, -0.9945218953682734, -0.9961946980917455, -0.9975640502598242,
			-0.9986295347545738, -0.9993908270190958, -0.9998476951563913, -1, -0.9998476951563913, -0.9993908270190958,
			-0.9986295347545738, -0.9975640502598243, -0.9961946980917455, -0.9945218953682734, -0.992546151641322,
			-0.9902680687415704, -0.9876883405951378, -0.9848077530122081, -0.9816271834476639, -0.9781476007338056,
			-0.9743700647852352, -0.9702957262759966, -0.9659258262890684, -0.9612616959383188, -0.9563047559630354,
			-0.9510565162951536, -0.945518575599317, -0.9396926207859083, -0.9335804264972017, -0.9271838545667874,
			-0.9205048534524405, -0.9135454576426011, -0.9063077870366498, -0.898794046299167, -0.891006524188368,
			-0.8829475928589271, -0.8746197071393956, -0.8660254037844386, -0.8571673007021123, -0.8480480961564261,
			-0.8386705679454243, -0.8290375725550416, -0.8191520442889918, -0.8090169943749476, -0.798635510047293,
			-0.7880107536067218, -0.7771459614569708, -0.7660444431189781, -0.7547095802227721, -0.7431448254773946,
			-0.7313537016191703, -0.7193398003386511, -0.7071067811865477, -0.6946583704589976, -0.6819983600624983,
			-0.6691306063588581, -0.6560590289905074, -0.6427876096865396, -0.6293203910498378, -0.6156614753256582,
			-0.6018150231520483, -0.5877852522924734, -0.5735764363510465, -0.5591929034707466, -0.544639035015027,
			-0.529919264233205, -0.5150380749100545, -0.5000000000000004, -0.4848096202463369, -0.4694715627858908,
			-0.45399049973954697, -0.4383711467890778, -0.4226182617406992, -0.40673664307580015, -0.3907311284892739,
			-0.37460659341591235, -0.35836794954530077, -0.3420201433256686, -0.3255681544571567, -0.3090169943749476,
			-0.29237170472273716, -0.27563735581699894, -0.2588190451025207, -0.24192189559966787, -0.22495105434386534,
			-0.20791169081775987, -0.19080899537654467, -0.1736481776669304, -0.15643446504023112, -0.13917310096006588,
			-0.12186934340514723, -0.10452846326765342, -0.08715574274765832, -0.06975647374412564, -0.05233595624294437,
			-0.034899496702500823, -0.01745240643728356
	};

/* End of file sin_LUT.c */
