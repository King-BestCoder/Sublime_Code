#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string chinese="zhong guo hang tian ke ji ji tuan wu yuan tian zhou yi hao zong she ji shi bai ming sheng xiang zhong xin she jie shao , yin di qiu can cun da qi zu li , kong jian zai tai kong gui dao yun xing xu yi ran liao tui dong pa sheng , yi wei chi yun xing gao du . ci wai , ri hou kong jian zhan zai ren yun xing xian ran , mei you huo yun fei chuan de zhi chi , shi wu fa wan cheng chang qi zai gui zhu liu ren wu de . zhe ye shi zhong guo hang tian yan fa tian zhou huo yun fei chuan de gen ben yuan yin zai tian zhou yi hao chu xian zhi qian , qian su lian xian zai nian tui chu jin bu hao xi lie huo yun fei chuan , ou zhou yu hang ju zai zhi nian jian yun xing guo zi dong zhuan yi fei xing qi ri ben yu zhou hang kong yan jiu kai fa ji gou zai nian shou ci fa she kong jian zhan zhuan yun fei xing qi mei guo tai kong tan suo gong si jin nian ze yan fa le long fei chuan , hai you mei guo a lian te ji shu xi tong gong si he gui dao ke xue gong si de tian e zuo huo yun fei chuan";
	string japanese="Shijou sainenshou de shougi no puro kishi to nari, yon nichi, debyū sen irai no renshou kiroku o ichi roku ni koushin shi ta bakari no aichi ken seto shi no chuugaku san nensei, fujii satoshi tai yon dan ga shougakusei o aite ni taikyoku shi, sashi kata nado o shidou shi mashi ta. aichi ken okazaki shi de hirakare ta shougi kyoushitsu ni ha jimoto no shougakusei oyoso kyuu zero nin ga sanka shi, fujii satoshi tai yon dan tachi ichi zero nin no puro ga itte goto ni kodomo tachi o mawatte iku rirē keishiki de taikyoku shi mashi ta. taikyoku ha puro gawa ga hisha kaku ochi no joutai de hajimari, kodomo tachi ha puro kishi no attouteki na tsuyo sa o mae ni tsugi no itte o shinken ni kangae te i mashi ta.";
	string english="The Sun is rising on a calm and cloudy morning in late February 2017, and Jamie Sneddon and I have an important collection to make. After a short drive along the north-east coast of Scotland – passing open fields, detached bungalows, and blooming bushes of gorse that shine with a radiant yellow under the grey sky – we arrive at the muddy entrance of a farmyard. Many of the locals here in the remote Scottish Highlands are crofters: they nurture and trade certain root vegetables and small numbers of livestock and poultry, a lifestyle first developed in the 19th Century. After opening a red and rusting gate, we disturb a vocal gaggle of geese and a few chickens. Through the wire fences that border the farm, we can also see a small flock of sheep. However, Sneddon has only one animal on his mind: a cat. He is hoping to catch a stray tomcat that rules the yard. The previous day, he had baited a small cage inside one of the farm's stone outbuildings with mackerel – cheap, smelly, and easy to split into portions – and cat food.";
	string s,str;
	int a=0,p,b=0,c=0;
	while(getline(cin,s)){
		stringstream sin(s);
		while(sin>>str){
			p=chinese.find(str);
			if(p!=string::npos){
				a++;
			}
			p=japanese.find(str);
			if(p!=string::npos){
				b++;
			}
			p=english.find(str);
			if(p!=string::npos){
				c++;
			}
		}
	}
	int d=max(a,max(b,c));
	if(a==d){
		printf("Chinese\n");
	}
	else if(b==d){
		printf("Japanese\n");
	}
	else if(c==d){
		printf("English\n");
	}
	return 0;
}