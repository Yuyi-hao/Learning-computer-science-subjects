// 355. Design Twitter
#define MAX_USERS 501

typedef struct Node{
    int user_id;
    int post_id;
    struct Node *next;
}Node;

typedef struct LL{
    struct Node *head;
    int size;
} LL;

typedef struct User{
    int id;
    int *followees;
} User;

typedef struct {
    struct LL *posts;
    struct User **users;    
} Twitter;


struct User *create_user(int user_id){
    struct User *user = (struct User *)malloc(sizeof(struct User));
    user->followees = (int *)calloc(MAX_USERS, sizeof(int));
    user->id = user_id;
    return user;
}

Twitter* twitterCreate() {
    Twitter *twitter = (Twitter *)malloc(sizeof(Twitter));
    twitter->users = (User **)calloc(MAX_USERS, sizeof(User *));
    twitter->posts = (struct LL *)malloc(sizeof(struct LL));
    twitter->posts->head = NULL;
    twitter->posts->size = 0;
    return twitter;
}

void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    struct Node *post = (struct Node *)malloc(sizeof(struct Node));
    post->user_id = userId;
    post->post_id = tweetId;
    post->next = obj->posts->head;
    obj->posts->head = post;
    obj->posts->size += 1;
}

int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    if(!(obj->users[userId])){
        obj->users[userId] = create_user(userId);
    }
    int *tweets = (int *)malloc(sizeof(int)*(10));
    int i=0;
    struct Node *temp = obj->posts->head;
    while(i < 10 && temp){
        if(obj->users[userId]->followees[temp->user_id] || temp->user_id == userId){
            tweets[i] = temp->post_id;
            i++;
        }
        temp = temp->next;
    }
    *retSize = i;
    return tweets;
}

void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    if(obj->users[followerId] == NULL){
        obj->users[followerId] = create_user(followerId);
    }
    if(obj->users[followeeId] == NULL){
        obj->users[followeeId] = create_user(followeeId);
    }
    obj->users[followerId]->followees[followeeId] = 1;
}

void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    if(obj->users[followerId] == NULL){
        obj->users[followerId] = create_user(followerId);
    }
    if(obj->users[followeeId] == NULL){
        obj->users[followeeId] = create_user(followeeId);
    }
    obj->users[followerId]->followees[followeeId] = 0;
}

void twitterFree(Twitter* obj) {
    for(struct Node *temp=obj->posts->head; temp;){
        struct Node *old_node = temp;
        temp = temp->next;
        free(old_node);
    }
    free(obj->posts);
    for(int i=0; i<MAX_USERS; i++){
        if(obj->users[i]){
            free(obj->users[i]->followees);
            free(obj->users[i]);
        }
    }
    free(obj->users);
    free(obj);
    return;
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/