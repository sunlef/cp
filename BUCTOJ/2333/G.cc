#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int N;
    // cout << "vector<vector<string>> ans(80);\n";

    // for (N = 2; N <= 79; ++N) {
    //     vector<int> A(10);
    //     iota(A.begin(), A.end(), 0);

    //     int CUTTOFF = 1;
    //     for (int i = 1; i <= 10; ++i) {
    //         CUTTOFF *= i;
    //     }

    //     vector<array<string, 2>> ans;

    //     for (int i = 0; i < CUTTOFF; ++i) {
    //         int a = 10000 * A[0] + 1000 * A[1] + 100 * A[2] + 10 * A[3] + A[4];
    //         int b = 10000 * A[5] + 1000 * A[6] + 100 * A[7] + 10 * A[8] + A[9];

    //         if (a % b == 0 && a / b == N) {
    //             array<string, 2> arr;
    //             for (int j = 0; j < 10; ++j) {
    //                 arr[j >= 5].push_back(A[j] + '0');
    //             }
    //             ans.push_back(arr);
    //         }

    //         next_permutation(A.begin(), A.end());
    //     }

    //     sort(ans.begin(), ans.end());

    //     for (auto [a, b] : ans) {
    //         cout << "ans[" << N << "].push_back(\"";
    //         cout << a << '/' << b << '=' << N << "\");\n";
    //     }
    // }

    vector<vector<string>> ans(80);
    ans[2].push_back("13458/06729=2");
    ans[2].push_back("13584/06792=2");
    ans[2].push_back("13854/06927=2");
    ans[2].push_back("14538/07269=2");
    ans[2].push_back("14586/07293=2");
    ans[2].push_back("14658/07329=2");
    ans[2].push_back("15384/07692=2");
    ans[2].push_back("15846/07923=2");
    ans[2].push_back("15864/07932=2");
    ans[2].push_back("18534/09267=2");
    ans[2].push_back("18546/09273=2");
    ans[2].push_back("18654/09327=2");
    ans[2].push_back("26970/13485=2");
    ans[2].push_back("27096/13548=2");
    ans[2].push_back("27690/13845=2");
    ans[2].push_back("29076/14538=2");
    ans[2].push_back("29370/14685=2");
    ans[2].push_back("29670/14835=2");
    ans[2].push_back("29706/14853=2");
    ans[2].push_back("29730/14865=2");
    ans[2].push_back("30972/15486=2");
    ans[2].push_back("32970/16485=2");
    ans[2].push_back("37092/18546=2");
    ans[2].push_back("37290/18645=2");
    ans[2].push_back("41358/20679=2");
    ans[2].push_back("41538/20769=2");
    ans[2].push_back("41586/20793=2");
    ans[2].push_back("46158/23079=2");
    ans[2].push_back("53418/26709=2");
    ans[2].push_back("53814/26907=2");
    ans[2].push_back("54138/27069=2");
    ans[2].push_back("54186/27093=2");
    ans[2].push_back("54618/27309=2");
    ans[2].push_back("58134/29067=2");
    ans[2].push_back("58146/29073=2");
    ans[2].push_back("58614/29307=2");
    ans[2].push_back("61458/30729=2");
    ans[2].push_back("61584/30792=2");
    ans[2].push_back("61854/30927=2");
    ans[2].push_back("62970/31485=2");
    ans[2].push_back("64158/32079=2");
    ans[2].push_back("65418/32709=2");
    ans[2].push_back("65814/32907=2");
    ans[2].push_back("69702/34851=2");
    ans[2].push_back("70296/35148=2");
    ans[2].push_back("70962/35481=2");
    ans[2].push_back("76290/38145=2");
    ans[2].push_back("76902/38451=2");
    ans[2].push_back("90276/45138=2");
    ans[2].push_back("90372/45186=2");
    ans[2].push_back("90762/45381=2");
    ans[2].push_back("92370/46185=2");
    ans[2].push_back("93702/46851=2");
    ans[2].push_back("96270/48135=2");
    ans[2].push_back("96702/48351=2");
    ans[2].push_back("97026/48513=2");
    ans[2].push_back("97032/48516=2");
    ans[2].push_back("97062/48531=2");
    ans[2].push_back("97230/48615=2");
    ans[2].push_back("97302/48651=2");
    ans[3].push_back("17469/05823=3");
    ans[3].push_back("17496/05832=3");
    ans[3].push_back("50382/16794=3");
    ans[3].push_back("53082/17694=3");
    ans[3].push_back("61749/20583=3");
    ans[3].push_back("69174/23058=3");
    ans[3].push_back("91746/30582=3");
    ans[3].push_back("96174/32058=3");
    ans[4].push_back("15768/03942=4");
    ans[4].push_back("17568/04392=4");
    ans[4].push_back("23184/05796=4");
    ans[4].push_back("31824/07956=4");
    ans[4].push_back("60948/15237=4");
    ans[4].push_back("68940/17235=4");
    ans[4].push_back("69408/17352=4");
    ans[4].push_back("81576/20394=4");
    ans[4].push_back("81756/20439=4");
    ans[4].push_back("86940/21735=4");
    ans[4].push_back("94068/23517=4");
    ans[4].push_back("94860/23715=4");
    ans[5].push_back("13485/02697=5");
    ans[5].push_back("13845/02769=5");
    ans[5].push_back("14685/02937=5");
    ans[5].push_back("14835/02967=5");
    ans[5].push_back("14865/02973=5");
    ans[5].push_back("16485/03297=5");
    ans[5].push_back("18645/03729=5");
    ans[5].push_back("31485/06297=5");
    ans[5].push_back("38145/07629=5");
    ans[5].push_back("46185/09237=5");
    ans[5].push_back("48135/09627=5");
    ans[5].push_back("48615/09723=5");
    ans[5].push_back("67290/13458=5");
    ans[5].push_back("67920/13584=5");
    ans[5].push_back("69270/13854=5");
    ans[5].push_back("72690/14538=5");
    ans[5].push_back("72930/14586=5");
    ans[5].push_back("73290/14658=5");
    ans[5].push_back("76920/15384=5");
    ans[5].push_back("79230/15846=5");
    ans[5].push_back("79320/15864=5");
    ans[5].push_back("92670/18534=5");
    ans[5].push_back("92730/18546=5");
    ans[5].push_back("93270/18654=5");
    ans[6].push_back("17658/02943=6");
    ans[6].push_back("27918/04653=6");
    ans[6].push_back("34182/05697=6");
    ans[7].push_back("16758/02394=7");
    ans[7].push_back("18459/02637=7");
    ans[7].push_back("31689/04527=7");
    ans[7].push_back("36918/05274=7");
    ans[7].push_back("37926/05418=7");
    ans[7].push_back("41832/05976=7");
    ans[7].push_back("53298/07614=7");
    ans[7].push_back("98532/14076=7");
    ans[8].push_back("25496/03187=8");
    ans[8].push_back("36712/04589=8");
    ans[8].push_back("36728/04591=8");
    ans[8].push_back("37512/04689=8");
    ans[8].push_back("37528/04691=8");
    ans[8].push_back("38152/04769=8");
    ans[8].push_back("41896/05237=8");
    ans[8].push_back("42968/05371=8");
    ans[8].push_back("46312/05789=8");
    ans[8].push_back("46328/05791=8");
    ans[8].push_back("46712/05839=8");
    ans[8].push_back("47136/05892=8");
    ans[8].push_back("47328/05916=8");
    ans[8].push_back("47368/05921=8");
    ans[8].push_back("51832/06479=8");
    ans[8].push_back("53928/06741=8");
    ans[8].push_back("54312/06789=8");
    ans[8].push_back("54328/06791=8");
    ans[8].push_back("54712/06839=8");
    ans[8].push_back("56984/07123=8");
    ans[8].push_back("58496/07312=8");
    ans[8].push_back("58912/07364=8");
    ans[8].push_back("59328/07416=8");
    ans[8].push_back("59368/07421=8");
    ans[8].push_back("63152/07894=8");
    ans[8].push_back("63528/07941=8");
    ans[8].push_back("65392/08174=8");
    ans[8].push_back("65432/08179=8");
    ans[8].push_back("67152/08394=8");
    ans[8].push_back("67352/08419=8");
    ans[8].push_back("67512/08439=8");
    ans[8].push_back("71456/08932=8");
    ans[8].push_back("71536/08942=8");
    ans[8].push_back("71624/08953=8");
    ans[8].push_back("71632/08954=8");
    ans[8].push_back("73248/09156=8");
    ans[8].push_back("73264/09158=8");
    ans[8].push_back("73456/09182=8");
    ans[8].push_back("74528/09316=8");
    ans[8].push_back("74568/09321=8");
    ans[8].push_back("74816/09352=8");
    ans[8].push_back("75328/09416=8");
    ans[8].push_back("75368/09421=8");
    ans[8].push_back("76184/09523=8");
    ans[8].push_back("76248/09531=8");
    ans[8].push_back("76328/09541=8");
    ans[8].push_back("83672/10459=8");
    ans[8].push_back("83752/10469=8");
    ans[8].push_back("84296/10537=8");
    ans[8].push_back("84632/10579=8");
    ans[8].push_back("84736/10592=8");
    ans[8].push_back("85392/10674=8");
    ans[8].push_back("85432/10679=8");
    ans[8].push_back("85936/10742=8");
    ans[8].push_back("86352/10794=8");
    ans[8].push_back("87456/10932=8");
    ans[8].push_back("87536/10942=8");
    ans[8].push_back("87624/10953=8");
    ans[8].push_back("87632/10954=8");
    ans[8].push_back("96584/12073=8");
    ans[8].push_back("98456/12307=8");
    ans[8].push_back("98760/12345=8");
    ans[9].push_back("57429/06381=9");
    ans[9].push_back("58239/06471=9");
    ans[9].push_back("75249/08361=9");
    ans[9].push_back("95742/10638=9");
    ans[9].push_back("95823/10647=9");
    ans[9].push_back("97524/10836=9");
    ans[12].push_back("45792/03816=12");
    ans[12].push_back("73548/06129=12");
    ans[12].push_back("89532/07461=12");
    ans[12].push_back("91584/07632=12");
    ans[13].push_back("67392/05184=13");
    ans[13].push_back("81549/06273=13");
    ans[13].push_back("94653/07281=13");
    ans[14].push_back("25746/01839=14");
    ans[14].push_back("27384/01956=14");
    ans[14].push_back("41538/02967=14");
    ans[14].push_back("46158/03297=14");
    ans[14].push_back("51492/03678=14");
    ans[14].push_back("54768/03912=14");
    ans[14].push_back("61572/04398=14");
    ans[14].push_back("65982/04713=14");
    ans[15].push_back("27945/01863=15");
    ans[15].push_back("92745/06183=15");
    ans[16].push_back("45936/02871=16");
    ans[16].push_back("73296/04581=16");
    ans[16].push_back("98352/06147=16");
    ans[17].push_back("26843/01579=17");
    ans[17].push_back("28543/01679=17");
    ans[17].push_back("29546/01738=17");
    ans[17].push_back("36958/02174=17");
    ans[17].push_back("45713/02689=17");
    ans[17].push_back("45781/02693=17");
    ans[17].push_back("54689/03217=17");
    ans[17].push_back("59126/03478=17");
    ans[17].push_back("64957/03821=17");
    ans[17].push_back("65297/03841=17");
    ans[17].push_back("67184/03952=17");
    ans[17].push_back("67218/03954=17");
    ans[17].push_back("76823/04519=17");
    ans[17].push_back("76891/04523=17");
    ans[17].push_back("78132/04596=17");
    ans[17].push_back("78523/04619=17");
    ans[17].push_back("78591/04623=17");
    ans[17].push_back("81532/04796=17");
    ans[17].push_back("83572/04916=17");
    ans[17].push_back("83657/04921=17");
    ans[17].push_back("89437/05261=17");
    ans[17].push_back("89471/05263=17");
    ans[17].push_back("89641/05273=17");
    ans[17].push_back("91426/05378=17");
    ans[17].push_back("92837/05461=17");
    ans[17].push_back("92871/05463=17");
    ans[17].push_back("93126/05478=17");
    ans[18].push_back("28674/01593=18");
    ans[19].push_back("51984/02736=19");
    ans[19].push_back("81567/04293=19");
    ans[22].push_back("51678/02349=22");
    ans[23].push_back("36294/01578=23");
    ans[23].push_back("81627/03549=23");
    ans[23].push_back("81972/03564=23");
    ans[24].push_back("39528/01647=24");
    ans[24].push_back("46872/01953=24");
    ans[26].push_back("42978/01653=26");
    ans[26].push_back("56498/02173=26");
    ans[26].push_back("61854/02379=26");
    ans[26].push_back("67314/02589=26");
    ans[26].push_back("67418/02593=26");
    ans[26].push_back("76518/02943=26");
    ans[26].push_back("82654/03179=26");
    ans[26].push_back("89726/03451=26");
    ans[26].push_back("92846/03571=26");
    ans[27].push_back("39852/01476=27");
    ans[27].push_back("49572/01836=27");
    ans[27].push_back("69741/02583=27");
    ans[27].push_back("96714/03582=27");
    ans[28].push_back("75348/02691=28");
    ans[29].push_back("37584/01296=29");
    ans[29].push_back("73689/02541=29");
    ans[32].push_back("75168/02349=32");
    ans[35].push_back("48265/01379=35");
    ans[35].push_back("63945/01827=35");
    ans[35].push_back("64295/01837=35");
    ans[35].push_back("74865/02139=35");
    ans[35].push_back("93485/02671=35");
    ans[37].push_back("65934/01782=37");
    ans[38].push_back("65892/01734=38");
    ans[38].push_back("74328/01956=38");
    ans[43].push_back("93654/02178=43");
    ans[44].push_back("58476/01329=44");
    ans[44].push_back("59268/01347=44");
    ans[44].push_back("67892/01543=44");
    ans[44].push_back("69432/01578=44");
    ans[44].push_back("95348/02167=44");
    ans[46].push_back("58374/01269=46");
    ans[52].push_back("95472/01836=52");
    ans[53].push_back("65879/01243=53");
    ans[53].push_back("75896/01432=53");
    ans[53].push_back("84376/01592=53");
    ans[53].push_back("92538/01746=53");
    ans[59].push_back("73986/01254=59");
    ans[62].push_back("79546/01283=62");
    ans[62].push_back("94736/01528=62");
    ans[66].push_back("83754/01269=66");
    ans[68].push_back("98736/01452=68");

    int N;

    while (cin >> N) {
        for (auto s : ans[N]) {
            cout << s << '\n';
        }
    }

    return 0;
}