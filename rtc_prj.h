void RTC_Init(void);

void SetRTCTime(u32,u32,u32);
void GetRTCTime(u32 *,u32 *,u32 *);
void DisplayRTCTime(u32,u32,u32);

void SetRTCdate(u32,u32,u32);
void GetRTCdate(u32 *,u32 *,u32 *);
void DisplayRTCdate(u32,u32,u32);

void SetRTCDay(u32);
void GetRTCDay(u32 *);
void DisplayRTCDay(u32);