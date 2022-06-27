#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL* curl;
    FILE* fp;
    errno_t err;
    CURLcode res;
    const char* url = "https://stackoverflow.com";
    char outfilename[FILENAME_MAX] = "page.html";
    curl = curl_easy_init();
    if (curl)
    {
        err = fopen_s(&fp, outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return 0;
}
