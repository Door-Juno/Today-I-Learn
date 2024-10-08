 # Github 어떻게 쓰는지 공부하는중 ...  
 ### 1. local 과 remote 연결  
 깃허브 페이지에서 repositories 를 만든 후 저장소 주소 뒤에 .git을 붙여준다 .   
 즉 https://github.com/아이디/저장소이름.git  

``` 
git remote add origin [원격저장소 주소]
```
만약 잘못 연결했다면 다음 명령어를 통해 삭제 가능하다.   
```
git remote rm origin
```

### 2. branch  
branch는 대충 설명해서 버전이다. 여러 branch를 통해 여러 버전으로 대응 가능 .  
```
//현재 브랜치 이름 확인
git branch
```
```
//브랜치 이름 바꾸기
git branch -m ooo xxx 
```  
추가로 로컬과 원격 저장소의 상태가 같아지도록 "README.md"를 pull 해야한다.
```
//원격 저장소의 파일을 가져오기
git pull origin [브랜치 이름]
```  
로컬 저장소가 최신 상태를 유지할 수 있도록, 파일을 깃허브에 올리기 전에 pull 하는 습관을 들이도록 하자.  

### 3. add -> commit -> push  
1. add  
원격 저장소에 올릴 파일들을 리스트에 올려준다.  
추가할 파일의 이름을 git add 뒤에 적어주면 된다.  
```
git add [파일 이름]
git add . // 폴더 파일의 변경된 모든 파일을 올릴때 . 사용
```  
add를 하기전 변경된 파일을 확인하고 싶다면 status 사용.  
```
git status  //초록색으로 뜨면 추적되었다는 뜻이다.
```  
만약 add를 했는데 취소하고 싶다면 ?  
```
git rm --cached -r . // add 모두 취소
git rm --cached [파일이름] // 특정 파일만 add 취소
```  
2. commit  
add한 파일을 검토하고 확정짓는다.  
```
git commit -m "커밋 메세지"
```  

3. push  
commit한 파일들을 원격 저장소에 올린다.  
```
git push origin [브랜치 이름]
git push -u main // main에 푸시합니다.
```  

4. 다음부터는...  
```
git pull origin main
git add . 
git commit -m "commit message "
git push origin main
```  
을 순서대로 입력해주면 됩니당..(main 브랜치 일떄만)