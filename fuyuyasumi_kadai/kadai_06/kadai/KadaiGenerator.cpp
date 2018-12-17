#include "pch.h"
#include "KadaiGenerator.h"


KadaiGenerator::KadaiGenerator()
{
	std::random_device rd;
	//—”‚ğ‰Šú‰»B
	m_mtRandom.seed(rd());
}


KadaiGenerator::~KadaiGenerator()
{
}
void KadaiGenerator::Generate(char* a)
{
	for (int i = 0; i < 100; i++) {
		a[i] = 'a' + m_mtRandom() % 26;
		m_a[i] = a[i];
	}
}
void KadaiGenerator::CheckAnswer(int* b)
{
	//‚±‚±‚©‚çA

	for (int i = 0; i < 100; i++) {
		if (m_a[i]  == 'k' ){
			if (b[i] != 1) {
				printf("ŠÔˆá‚Á‚Ä‚¢‚é‚æ(LEƒÖEM)\n");
				return;
			}
		}else if (m_a[i] == 'b') {
			if (b[i] != 2) {
				printf("ŠÔˆá‚Á‚Ä‚¢‚é‚æ(LEƒÖEM)\n");
				return;
			}
		}else if (m_a[i] == 'c') {
			if (b[i] != 3) {
				printf("ŠÔˆá‚Á‚Ä‚¢‚é‚æ(LEƒÖEM)\n");
				return;
			}
		}
		else {
			if (b[i] != 4) {
				printf("ŠÔˆá‚Á‚Ä‚¢‚é‚æ(LEƒÖEM)\n");
				return;
			}
		}
	}
	
	printf("‰Û‘èƒNƒŠƒAIII\n");
}
