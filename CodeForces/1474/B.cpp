#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
int d;
long long ans[] = {6,15,35,77,143,221,323,437,667,899,1147,1517,1763,2021,2491,3127,3599,4087,4757,5183,5767,6557,7387,8633,9797,10403,11021,11663,12317,14351,16637,17947,19043,20711,22499,23707,25591,27221,28891,30967,32399,34571,36863,38021,39203,41989,47053,50621,51983,53357,55687,57599,60491,64507,67591,70747,72899,75067,77837,79523,82919,89951,95477,97343,99221,104927,111547,116939,121103,123197,126727,131753,136891,141367,145157,148987,154433,159197,164009,171371,176399,181451,186623,190087,194477,198907,205193,210677,213443,216221,223693,233273,239117,245009,250997,256027,265189,272483,282943,295927,304679,313591,320347,324899,329467,338699,348091,355207,359999,364807,372091,378221,381923,390589,404471,412163,416021,422491,430327,435599,444853,455621,462391,471953,484391,497009,509771,522713,532891,541687,549077,557993,568507,576077,585209,594437,608351,627239,644773,656099,665831,675683,680621,685583,695531,715667,731021,736163,741317,756851,772637,777923,783221,804509,826277,837209,853751,870473,881717,891127,902491,921551,938957,948667,960391,974153,988027,1005973,1022117,1032247,1040399,1052651,1065023,1073287,1089911,1102499,1115111,1127843,1136347,1162003,1185917,1192463,1199021,1209991,1223227,1238753,1254391,1267867,1299479,1327103,1340939,1361873,1382951,1401847,1416091,1432793,1456813,1476221,1488391,1503067,1512899,1522747,1545013,1572491,1607743,1633283,1640957,1653787,1664099,1674427,1687397,1695203,1703021,1723933,1742399,1752967,1806047,1860487,1876891,1896113,1932019,1971191,2005007,2030621,2039183,2047757,2062087,2082233,2099597,2108303,2119927,2146189,2178551,2196323,2205221,2214143,2223077,2238007,2264989,2301253,2331713,2362333,2390107,2405597,2421127,2442953,2461757,2480609,2499557,2528051,2556797,2572807,2585663,2595317,2611447,2624399,2637367,2663399,2712509,2755591,2772221,2782223,2825617,2873021,2883203,2903591,2941189,2965283,2985959,3017153,3041527,3062491,3083527,3125743,3168391,3186221,3196943,3221989,3261611,3301453,3337913,3381857,3437267,3474487,3493157,3504383,3515621,3526883,3549431,3590989,3625207,3648091,3694003,3732623,3767417,3802499,3849323,3904567,3932273,3960091,3980021,3992003,4003997,4028033,4056187,4088459,4112783,4137131,4186067,4235339,4268347,4305589,4334723,4347221,4359743,4384811,4430989,4460543,4498577,4536899,4553947,4575317,4588163,4613879,4652633,4708819,4800337,4862021,4884091,4915073,4968377,5008643,5022077,5048993,5103017,5143823,5157437,5184713,5216647,5244091,5267021,5303773,5336099,5391563,5456887,5475599,5494327,5517797,5541307,5588447,5635867,5659637,5673923,5692987,5716877,5740807,5783989,5827387,5856391,5904851,5948717,5973127,6017173,6066353,6100891,6125621,6199931,6310063,6380651,6426209,6456677,6482107,6502499,6522907,6594503,6682189,6718463,6765137,6827753,6859157,6901093,6969551,7033079,7064963,7080917,7112873,7150267,7182391,7209221,7225343,7241477,7268407,7306193,7338677,7354943,7376647,7420151,7452899,7485671,7535009,7567997,7617551,7683959,7745053,7784099,7806427,7834397,7851203,7901657,7986227,8037221,8065591,8105393,8145307,8173877,8236819,8311673,8363639,8409991,8444827,8485553,8538059,8602453,8678867,8732021,8761591,8797147,8820899,8910029,8999999,9036011,9090209,9126437,9180851,9235517,9272009,9332989,9388087,9443293,9492557,9523387,9603701,9696971,9734399,9790577,9922331,10017221,10036223,10080589,10137847,10169717,10220773,10278427,10323353,10361957,10400609,10497479,10575503,10595021,10614563,10660189,10791029,10889999,10916407,10956091,10995847,11029037,11062267,11088899,11135533,11189021,11242573,11289599,11329931,11370383,11431097,11492099,11553137,11628091,11716829,11840417,11923193,11964677,11985443,12006221,12027023,12110279,12215009,12284989,12348187,12404459,12446783,12467957,12503287,12531599,12559927,12616679,12659363,12709189,12787751,12830723,12873719,12959951,13032091,13068221,13104391,13155113,13205947,13249591,13329737,13432189,13483583,13505621,13571807,13645627,13682597,13727009,13793771,13860713,13912891,13957687,14062379,14167687,14197823,14243051,14333747,14402021,14439991,14531263,14607683,14653559,14745551,14814797,14837903,14884139,14976851,15046637,15093209,15194323,15280277,15319387,15350723,15374237,15413467,15444899,15499933,15563021,15657749,15824363,15959989,16016003,16040021,16080091,16128247,16160399,16192567,16305323,16402499,16434907,16524161,16613767,16687189,16744463,16777207,16850989,16966097,17040383,17065157,17106487,17189267,17264021,17288963,17372143,17547577,17690411,17757787,17791523,17842151,17892899,17943671,17994563,18045479,18113527,18147599,18198731,18249983,18301259,18369787,18429833,18593119,18766199,18818243,18870311,18948593,19009591,19079399,19201843,19307227,19386373,19492189,19554083,19642543,19749127,19793597,19838107,19891591,19998703,20088323,20142119,20249951,20340091,20385221,20412323,20439437,20566081,20684303,20747989,20830087,20930561,21040553,21104827,21159991,21270463,21427577,21511043,21538877,21585307,21622499,21659707,21715591,21790199,21864967,21949189,22061773,22202863,22297283,22335067,22382357,22486483,22610009,22762297,22896221,22924943,22953677,23001607,23039999,23107213,23184221,23270927,23483491,23677931,23755867,23843653,23970767,24068827,24147371,24255589,24324623,24354221,24403591,24472793,24542107,24621419,24681023,24710837,24800351,24900091,24960007,25009997,25060027,25100099,25160231,25220483,25310897,25451989,25553009,25684543,25796237,25847047,25938613,26009999,26050807,26112091,26173447,26347493,26522491,26625551,26718557,26780609,26873831,26967233,27071173,27227443,27342437,27373823,27405221,27551857,27741253,27836167,27878399,27973457,28089991,28153627,28259807,28387559,28515551,28611797,28793731,28987447,29052091,29116807,29192393,29268091,29322221,29354723,29430589,29528347,29582717,29615363,29658907,29811479,29964667,30008483,30041357,30161983,30272003,30305021,30393133,30470399,30514567,30569837,30735767,30913591,30980347,31036037,31102913,31203371,31438193,31708097,31809599,31854727,31911197,31945103,31979021,32012963,32080871,32216927,32330587,32387477,32455793,32558411,32649787,32798429,32936117,32970563,33016507,33223471,33419957,33489353,33593591,33686407,33756091,33837473,33918967,34023853,34117277,34175707,34222499,34269307,34327877,34386487,34433423,34503851,34574399,34680257,34809991,34963469,35105621,35200453,35354867,35604893,35808247,35963909,36108077,36240319,36397073,36481591,36542021,36602491,36723551,36844891,36917767,37015031,37088099,37161191,37295413,37417673,37527851,37601423,37675019,37785593,37908613,38044199,38254081,38415203,38452397,38526833,38613787,38675957,38750609,38912563,39087479,39187591,39262747,39312899,39363067,39463499,39601813,39689999,39765611,39866587,39942391,40018267,40106873,40195591,40297079,40398727,40449599,40500487,40576891,40653367,40755431,40870433,41075137,41267767,41447723,41602499,41731519,41873837,41951513,42068171,42327811,42575609,42745363,42889397,42928703,43007339,43112347,43164899,43217467,43283237,43428019,43599593,43731733,43930303,44155961,44302327,44355599,44448853,44568967,44675831,44756099,44836391,44916803,44970427,45077771,45239027,45360221,45548857,45724643,45846377,45968399,46049771,46131263,46212779,46416869,46580621,46621583,46662557,46744553,46908737,47059591,47141947,47196899,47293093,47485817,47651393,47734277,47803387,48052399,48274703,48358091,48441599,48497287,48566957,48636667,48720391,48818153,48916027,48985997,49098013,49224247,49322513,49463053,49575677,49702451,49885933,50041451,50282137,50495227,50623189,50751367,50808383,50979479,51194009,51380143,51581099,51696091,51839951,51969677,52012943,52070647,52186151,52316273,52417591,52490021,52562491,52823599,53144051,53319179,53406863,53509189,53670251,53758223,53890217,54022499,54169519,54479017,54789523,54967387,55130561,55383283,55562107,55621763,55770943,55935437,56010247,56070143,56160011,56294993,56430119,56550391,56640667,56746073,56836517,56911927,56972303,57062891,57153599,57259453,57380621,57456391,57547387,57608099,57714373,57836021,57972947,58216819,58384877,58461307,58660181,58844237,58936313,59043847,59120717,59213009,59305397,59444051,59598391,59675621,59814707,60015973,60140021,60186563,60434851,60699677,60917881,61152391,61246267,61387189,61575373,61779551,61936891,62015621,62062883,62110157,62283583,62473207,62615533,62773913,62884891,62964221,63091213,63202499,63313813,63648259,64015937,64160099,64224187,64448663,64738067,64899127,65028071,65205589,65351047,65415743,65464277,65561393,65707211,65836987,65934391,66178081,66487667,66650887,66732557,66830609,66994189,67239919,67469771,67568399,67667051,67765823,67815221,67897591,68111909,68326747,68409437,68558351,68707517,68757263,68807021,68956367,69122587,69272293,69572137,69856139,69989947,70107113,70257899,70358543,70626991,70913237,70997467,71064899,71182933,71318021,71470067,71639287,71977967,72369013,72539273,72658567,72794999,72897443,72948677,73153709,73410599,73564913,73770857,73925603,74028791,74235407,74390621,74442383,74563189,74718727,74908961,75099547,75220913,75325037,75429209,75533477,75620407,75742193,75864091,75968647,76125589,76282747,76370117,76457527,76562491,76685033,76912819,77105957,77316749,77528021,77668933,77792399,77898251,78039547,78110243,78216311,78410989,78535043,78588221,78801029,79032091,79352239,79673467,79762757,79869953,80030891,80227813,80389147,80460899,80730029,80999999,81072007,81162077,81216143,81378377,81631189,81757763,81830107,81974891,82137953,82428097,82755373,82919227,83137843,83356891,83448221,83612687,83795707,83887277,84033853,84217313,84345847,84511213,84658397,84750427,84916189,85082167,85248253,85377599,85543937,85877189,86099837,86155523,86266919,86527123,86769209,86881037,87048851,87216917,87272963,87347707,87609479,87871867,88059407,88247227,88359991,88510439,88661047,88736399,88849451,88962623,89019221,89075843,89302379,89529443,89586221,89680891,89794567,89965189,90136027,90325967,90554231,90763693,90935287,91068833,91183397,91565437,92044787,92294413,92467447,92563637,92659867,92736899,92871733,93045307,93218989,93489497,93663683,93779831,93954233,94245143,94478399,94614493,94789687,94887077,94984507,95218483,95413823,95550589,95726647,95824517,95981173,96177233,96314587,96491293,96648557,96746887,96923989,97101307,97180163,97318189,97555093,97713221,97891187,98089207,98307161,98525467,98604899,98724071,98903009,99161683,99400891,99799811,100160063,100460333,100761443,101002379,101284087,101364623,101485451,101707189,101848463,101929207,102030197,102151433};
bool prime(int x){
	if(x <= 1)
		return false;
	else
		for(int i = 2; i <= sqrt(x); ++i)
			if(x % i == 0)
				return false;
	return true;
}
void solve(){
	cin >> d;
	int cnt = 0;
	for(int i = 2; i <= d; ++i)
		if(prime(i))
			++cnt;
	cout << ans[cnt] << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}