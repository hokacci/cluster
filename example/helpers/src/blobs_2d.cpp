#include <vector>

#include "blobs_2d.h"
#include "point_2d.h"

std::vector<Point2D> dataset_blobs_2d = {
	{4.05395198, -4.32097976},	{7.44235089, -2.00921666},	{10.66549625, -2.33245035}, {2.677733, -2.43063087},
	{1.93428228, -6.91751417},	{2.51424209, -2.52936438},	{2.66688617, -6.9484486},	{2.81855595, -1.88198715},
	{8.45313953, -3.03859904},	{3.10150904, -6.19777386},	{9.50331269, -3.47916365},	{8.61394704, -3.27570642},
	{10.23557253, -3.88220083}, {4.47801161, -6.64564217},	{1.75079348, -2.98547965},	{3.61612625, -6.51036372},
	{10.09224378, -2.11396007}, {8.65822626, -3.14451924},	{9.70433093, -1.9318645},	{3.24956315, -7.21160023},
	{3.90417187, -1.64629726},	{0.80672571, -8.40886536},	{8.73576267, -3.49103516},	{2.82519746, -7.20824605},
	{9.84337598, -3.05235371},	{3.66879828, -2.64356305},	{2.31083957, -3.20000737},	{2.58037701, -3.44882794},
	{9.69673727, -3.01908548},	{8.7443144, -2.92157522},	{8.68172354, -3.44484786},	{3.35610214, -2.00491451},
	{3.7783942, -3.64284711},	{3.01050764, -0.55968285},	{3.73951565, -7.46138815},	{4.42270106, -7.86452927},
	{2.097891, -0.41600488},	{8.90884237, -2.36307746},	{3.01716731, -3.49188567},	{10.72484487, -2.22933604},
	{9.27989805, -2.57688539},	{3.86344109, -7.72881},		{2.06202622, -6.82720528},	{3.22081958, -7.32883841},
	{6.94198175, -3.9701751},	{4.38172191, -5.08191533},	{10.89216038, -4.82688245}, {3.00589923, -5.49920189},
	{10.71730845, -3.24276644}, {9.61665115, -3.17265625},	{9.02499607, -2.69540779},	{4.78947588, -6.58718498},
	{9.83312592, -2.86855804},	{8.91949069, -2.26346218},	{3.5602039, -7.34315014},	{4.47848463, -7.25248167},
	{3.5159497, -0.88212547},	{4.29509062, -6.42300508},	{4.09370265, -7.48072943},	{9.96812621, -4.35298684},
	{4.9409483, -7.77058398},	{8.00378476, -3.96561314},	{2.24397795, -7.8572047},	{3.47782498, -0.31061759},
	{2.25959538, -2.01678467},	{4.3916041, -1.64162078},	{9.87175107, -1.02359086},	{3.5712983, -5.1135718},
	{4.30838061, -3.04978533},	{3.39551579, -6.90303357},	{1.82233739, -6.32122662},	{2.53338341, -0.19973437},
	{3.85276692, -5.18967411},	{9.49711774, -3.45004021},	{9.02267578, -3.12159658},	{7.80697275, -1.66099494},
	{2.67638516, -2.31356772},	{3.54635995, -7.00290337},	{2.41129749, -1.07945434},	{3.29781298, -7.09026436},
	{10.77035304, -2.80894938}, {3.40654706, -6.53861749},	{2.07251737, -3.12115876},	{3.26763138, -1.5719929},
	{9.9520754, -3.00558052},	{3.29501008, -3.20632192},	{9.54187149, -2.63607049},	{3.62242498, -3.2934369},
	{7.46907172, -2.70962493},	{5.90336667, -2.71113737},	{2.7681439, -6.97353687},	{3.87339319, -2.97979351},
	{10.59401429, -3.83931806}, {4.56791852, -6.18294346},	{9.37184763, -3.24864624},	{9.7247335, -5.1745006},
	{9.93781069, -3.53664424},	{0.79897409, -1.4472485},	{9.4323144, -3.31307445},	{3.25452317, -4.11244238},
	{4.55715459, -5.55600791},	{2.23347857, -6.32889306},	{9.55447598, -3.63588401},	{8.71253225, -2.07794091},
	{3.41854845, -5.99350757},	{3.40562474, -5.63459574},	{8.77715361, -3.15998876},	{9.54257227, -2.18758775},
	{2.29943066, -5.60961036},	{9.11397889, -2.19217317},	{9.14236434, -4.61189734},	{3.56436256, -5.52394213},
	{2.52320361, -4.63183541},	{8.82421937, -2.64763749},	{3.36622798, -6.58475211},	{10.02623174, -3.10945697},
	{3.08850386, -2.84505639},	{3.13120497, -3.78892231},	{4.27387337, -6.23737388},	{2.47894441, -1.35503487},
	{3.21455111, -1.94796879},	{3.4888962, -5.75442679},	{3.20009499, -5.08175751},	{3.91759159, -6.393314},
	{3.14529489, -2.99946286},	{1.48920335, -2.30515394},	{3.19726464, -1.91443084},	{9.64710782, -4.17621882},
	{8.79545713, -1.92804293},	{3.13520407, -7.03409102},	{3.5139434, -6.61945803},	{10.35337931, -1.77425882},
	{1.97498396, -8.07490143},	{9.74627124, -3.01921225},	{1.86252379, -6.21019502},	{3.48251501, -2.75766336},
	{1.90504518, -2.3722686},	{2.38033138, -7.31994595},	{9.2875328, -1.89460705},	{3.59828433, -0.59125533},
	{9.57338657, -3.40580041},	{10.76509089, -4.78902485}, {2.45956368, -2.55712327},	{4.40622002, -7.28204729},
	{3.54674944, -5.83437439},	{1.95834532, -2.01834458},	{9.25150587, -2.14736538},	{10.15777538, -3.28954402},
	{5.26164306, -6.14519318},	{3.09075257, -7.58687904},	{9.67238792, -3.3561193},	{3.3205681, -1.87092223},
	{9.70315713, -2.96309713},	{3.04096047, -2.23039166},	{4.48051198, -4.84098768},	{1.16221582, -0.71479224},
	{0.99868517, -2.02059701},	{2.62266843, -0.63762805},	{10.21094656, -4.67908655}, {11.07729268, -4.16715069},
	{2.54578364, -7.50008539},	{7.96439697, -4.04509583},	{8.50331376, -2.75803745},	{3.79706571, -8.74538219},
	{1.61219262, -7.2807833},	{3.10116808, -6.16405058},	{8.06370262, -2.52750743},	{4.65761925, -1.9797396},
	{7.91857733, -3.34750352},	{8.37714928, -4.33647604},	{3.37104446, -7.78852947},	{2.09679618, -2.62827408},
	{3.76183203, -3.87996622},	{3.33789963, -2.76497881},	{2.74409781, -6.04960199},	{2.19364135, -3.23778707},
	{3.23251566, -7.54060493},	{2.24391062, -1.98697436},	{1.61772577, -2.22149462},	{3.04483362, -6.17389246},
	{4.12472622, -0.67728333},	{1.71707799, -6.57256292},	{2.15128352, -1.86579306},	{8.48425135, -1.48131662},
	{3.03809473, -6.30292436},	{3.79599676, -3.77277555},	{4.25063911, -6.79580686},	{2.94171117, -0.39180495},
	{3.04042684, -4.09298519},	{1.72757063, -1.48419152},	{4.26671789, -1.62464512},	{3.99634283, -4.30619993},
	{9.35676572, -3.66664533},	{2.00424076, -6.03980281},	{2.00950208, -9.25542349},	{5.06615376, -3.79356754},
	{2.73810972, -6.75123817},	{3.02822402, -1.55604763},	{3.28888785, -5.76639061},	{2.49585425, -4.31233559},
	{3.32759962, -7.40575052},	{0.85397205, -6.93658099},	{3.79796189, -5.25554392},	{1.06825623, -2.59129625},
	{8.47932646, -2.65408518},	{4.1508985, -2.66705246},	{2.57549742, -5.49312601},	{2.63372251, -7.18694528},
	{3.23082742, -6.195189},	{1.12621217, -2.38799982},	{2.03795189, -3.86142156},	{8.29462572, -4.18052808},
	{4.32977429, -5.24259954},	{10.15862445, -4.38833223}, {2.61734253, -2.25731845},	{2.2588769, -2.02931403},
	{8.26165104, -3.12387228},	{3.15309179, -1.88023372},	{2.9475635, -7.30160339},	{9.94065486, -2.94727342},
	{1.30087543, -3.62814439},	{4.0036886, -6.17728913},	{9.41694962, -2.3144669},	{10.11661554, -3.0192127},
	{2.30849494, -5.39755159},	{2.59187517, -2.74572728},	{9.05131876, -4.07303112},	{10.58453788, -1.82142889},
	{2.62293589, -1.81873678},	{3.55589849, -5.41408926},	{8.59844018, -3.71516668},	{8.94988278, -1.70223964},
	{2.23320866, -7.3806311},	{1.84941383, -2.38469564},	{9.14228704, -2.79462775},	{2.62706574, -1.96068277},
	{3.30844817, -5.15589508},	{2.6753398, -6.47706734},	{9.93494721, -4.75238178},	{8.32661899, -3.15844242},
	{3.58770946, -6.19641677},	{4.39980079, -1.14661805},	{9.86249667, -1.05688746},	{0.61596523, 1.1098532},
	{2.8663684, -2.4511209},	{9.70266657, -3.09187905},	{8.17863776, -3.71861849},	{8.26874417, -2.02616386},
	{2.21635341, -2.37960399},	{2.87709273, -2.85250917},	{2.63231786, -8.13938683},	{3.46299451, -2.99092184},
	{3.07109262, -6.22477175},	{2.34018078, -5.64466809},	{3.36690126, -6.42352309},	{4.78175202, -2.73987985},
	{1.96028383, -7.93527235},	{9.51873601, -2.62638389},	{7.72907656, -2.14170304},	{8.78681206, -2.98052306},
	{4.24375251, -7.34305931},	{4.20531716, -5.71187364},	{1.98323368, -5.83789074},	{1.72385963, -2.29598141},
	{10.62936997, -2.06441811}, {9.60907916, -2.95267458},	{9.09695994, -1.77767836},	{5.44395614, -7.87954058},
	{3.91925769, -6.05598737},	{9.02694338, -3.3048852},	{3.66564723, -4.17826811},	{8.4863568, -3.17020463},
	{1.48515715, -6.99992428},	{3.12282038, -8.58595513},	{4.19088496, -3.30192246},	{4.44898296, -6.30630953},
	{4.20227637, -8.11363095},	{2.78626132, -5.8311227},	{1.95969894, -6.79103029},	{3.2263337, -4.97435274},
	{1.85346176, -1.9340472},	{9.39898313, -3.41065292},	{9.37582423, -2.06116253},	{4.43664647, -6.27146659},
	{2.34753296, -7.72622549},	{4.06724016, -2.4908764},	{9.74174226, -2.6265356},	{2.18520197, -2.02117564},
	{-0.02049688, -0.76813983}, {3.55971042, -7.53303546},	{8.59869721, -1.41919386},	{9.13803947, -2.41304295},
	{9.18764397, -3.29397277},	{4.1167645, -2.23709427},	{4.23347288, -5.96714979},	{3.31099486, -7.99339806},
	{1.92897419, -3.49674413},	{7.60234818, -3.78253077},	{11.95646911, -2.68486109}, {9.67161704, -2.00872801},
	{11.62625926, -3.35950018}, {4.94933196, -2.16433821},	{9.39849166, -3.36536798},	{8.9769044, -2.62255821},
	{3.69337163, -3.42980858},	{9.64732473, -3.11300208},	{3.2994507, -1.86357848},	{3.12422428, -2.99763093},
	{10.16707054, -3.05310798}, {3.63890029, -7.51286313},	{2.19155348, -0.71468697},	{10.34415632, -1.41012309},
	{7.24386094, -3.96309908},	{5.06821159, -3.14029194},	{9.45845201, -2.23474188},	{8.56456929, -2.50080439},
	{3.48996617, -6.86514139},	{3.76077561, -2.95612387},	{3.09255841, -7.49698894},	{3.44297482, -1.75135109},
	{9.38552866, -1.05703522},	{3.25897206, -6.51577447},	{10.44631368, -3.8518346},	{8.76780408, -2.11047136},
	{10.97765191, -3.78090771}, {2.3591096, -8.9247765},	{9.48660664, -2.56943368},	{11.59679145, -4.75906934},
	{7.70339633, -2.21126777},	{3.38688424, -4.37974037},	{2.70945773, -2.60168505},	{4.31759286, -7.58299781},
	{3.71767603, -3.24441211},	{3.64106429, -1.98054234},	{3.05614585, -4.05681433},	{2.39218605, -2.27196838},
	{4.87604868, -6.42111004},	{9.4045232, -3.10642153},	{1.43904591, -8.69029303},	{1.92609005, -2.93507164},
	{4.98586364, -2.92554676},	{3.40979965, -1.67878163},	{3.41450825, -7.66068455},	{4.83795551, -6.48707701},
	{2.20294276, -6.25860426},	{1.81201265, -1.13034948},	{10.27375949, -2.51937387}, {4.08008545, -6.89024551},
	{4.68246147, -7.90873861},	{0.80400356, -7.21614716},	{3.06627684, -1.97138895},	{4.54019515, -5.772244},
	{1.64506607, -3.99591094},	{5.25061843, -6.6506536},	{1.78272691, -3.7006743},	{3.69592777, -5.52152206},
	{3.97420627, -7.61977654},	{4.44277955, -7.20253249},	{2.86779597, -2.77734042},	{8.80427249, -3.3078379},
	{4.20107763, -5.81688275},	{3.58344056, -8.61459823},	{10.03614537, -4.86748944}, {2.91289848, -2.83503797},
	{9.82063643, -3.04402091},	{9.39001471, -3.56089438},	{10.07050691, -2.76445784}, {9.0518459, -4.21189849},
	{3.1121578, -3.75318934},	{8.62585108, -3.94369128},	{10.52359885, -3.00681542}, {2.87723391, -1.57946761},
	{3.86788858, -4.08549547},	{3.17230283, -2.41208364},	{10.40266379, -3.52683517}, {2.37845997, -7.41918347},
	{3.46818438, -6.62327046},	{4.58759457, -1.50760401},	{9.89547787, -2.63425608},	{2.4699805, -8.16513318},
	{9.63406831, -3.41614596},	{11.25168325, -2.63519895}, {12.40735895, -2.35126688}, {4.41085009, -2.5075515},
	{2.45985542, -1.32054811},	{10.33259756, -2.84385838}, {1.15690829, -0.79993484},	{7.63064935, -3.65144933},
	{3.88543101, -3.42879475},	{2.82325294, -7.32128862},	{3.82311439, -8.88521927},	{3.74084564, -3.01410038},
	{4.04038271, -6.78238417},	{3.07598226, -6.49951663},	{1.57663865, -4.42463775},	{3.41736201, -5.95840084},
	{2.75450502, -3.28060749},	{7.1703629, -3.37107853},	{7.073169, -1.77766385},	{10.2539939, -3.49069063},
	{2.1814683, -1.53594236},	{2.4731929, -1.80764948},	{3.11137951, -0.4516277},	{7.37593377, -5.23138005},
	{2.80266143, -7.15800132},	{11.81059339, -0.86968416}, {3.45625841, -7.21742705},	{1.71958835, -2.40636531},
	{3.50567762, -7.94483128},	{3.45796843, -2.88347691},	{4.10308534, -6.89375229},	{3.09896757, -6.41452543},
	{4.02247739, -8.5747055},	{9.6287611, -4.16190238},	{1.90555608, -3.72335118},	{2.70064612, -5.86252461},
	{2.4727017, -3.44010555},	{1.97908786, -2.69703254},	{3.20602412, -3.3768646},	{3.31158194, -2.78018876},
	{2.30472279, -8.47128749},	{3.42453361, -6.98990903},	{9.76349028, -3.44292018},	{2.59722521, -1.84666273},
	{1.82555858, -3.66914742},	{3.02326649, -7.94610788},	{8.07070968, -4.06100573},	{2.92345929, -7.69301293},
	{4.14481057, -2.51887497},	{2.93600599, -4.75286838},	{1.26180023, -7.51323239},	{8.23060116, -3.69413346},
	{4.58187278, -7.62831127},	{2.72405251, -2.55149907},	{9.77880477, -1.47592805},	{2.74140155, -2.78953168},
	{3.29043175, 0.46009263},	{9.44716548, -0.67231696},	{3.21801893, -6.52830116},	{10.42783548, -2.32409109},
	{3.23975036, -4.56605068},	{4.01174229, -5.82403566},	{9.22357359, -3.51195725},	{10.27903903, -3.17451175},
	{9.28274106, -2.63261137},	{2.75127102, -7.63653635},	{9.88433242, -2.16180692},	{2.49871402, -2.24543951},
	{1.30638035, -6.89343583},	{1.16700853, -7.98507282},	{3.35287492, -3.31929279},	{8.24122425, -3.66579651},
	{4.31817663, -7.6962589},	{3.1336446, -6.45230611},	{1.60662662, -7.24920821},	{3.3181046, -1.7994488},
	{3.87592097, -7.48631976},	{9.84213508, -2.79294596},	{3.76959319, -3.3633718},	{8.8541798, -3.77818403},
	{2.22431787, -1.68140077},	{3.43362731, -1.43067439},	{2.38619068, -2.57539606},	{3.81501869, -3.77580517},
	{10.41854475, -1.8892223},	{10.75314683, -2.66328824}, {2.11882289, -3.16021872},	{1.92947239, -7.34967288},
	{3.93357051, -2.92190466},	{2.79301299, -5.93393355},	{2.1509219, -2.72203359},	{3.16957253, -6.32483445},
	{1.96266733, -7.56389913},	{3.95375009, -1.91226391},	{9.47075728, -2.49702437},	{9.91041928, -2.87700819},
	{9.79268372, -1.81436888},	{8.58180605, -2.57225807},	{1.76937992, -0.2107784},	{1.80063567, -3.13663081},
	{2.24053088, -7.02936078},	{9.09683143, -3.22425084},	{9.32959859, -2.83994173},	{2.3323159, -3.2780013},
	{4.46109627, -2.27753226},	{8.61294327, -1.6323139},	{2.853678, -0.99097422},	{2.33679173, -3.2349294},
	{8.80113519, -2.85556615},	{2.03444914, -7.1685607},	{1.40921424, -2.9822267},	{8.7381637, -2.08376128},
	{2.49412422, -2.4894085},	{2.84694911, -3.6306606},	{4.06421879, -7.47512687},	{4.22329164, -5.49035858},
	{1.92112942, -1.43031292},	{2.20694207, -0.50815816},	{2.48500328, -1.36590282},	{9.55203255, -3.74541802}
};