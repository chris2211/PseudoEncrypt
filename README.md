# PseudoEncrypt
1. pseudoEncrypt()实现
2. testPseudoEncryptRange()，testPseudoEncryptDuplicate()用于测试,testPseudoEncryptRange()返回有多少个
3. boundPseudoEncrypt8()用于生成8位的id
4. 可以通过1366*r1 + 150889) % 714025) / 714025.0) * 32767这个来数值的微调来避免预测，或者考虑使用pg wiki上推荐的Skip32(32bit)或者XTEA(64bit)
