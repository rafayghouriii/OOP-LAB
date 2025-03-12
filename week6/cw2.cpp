#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MediaFile
{
       protected:
       string filePath;
       double size;
       
       public:
       MediaFile(const string& path, double sz) : filePath(path), size(sz) {}

       virtual ~MediaFile() = default;

       virtual void play()
       {
              cout << "playing media file: " << filePath << endl;
       }

       virtual void stop()
       {
              cout << "stopping media file: " << filePath << endl;
       }

       virtual void display() const
       {
              cout << "file path: " << filePath << ", size: " << size << " mb" << endl;
       }
};

class VisualMedia : virtual public MediaFile
{
       protected:
       string resolution;
       
       public:
       VisualMedia(const string& path, double sz, const string& res) : MediaFile(path, sz), resolution(res) {}

       void display() const override
       {
              MediaFile::display();
              cout << "resolution: " << resolution << endl;
       }
};

class AudioMedia : virtual public MediaFile
{
       protected:
       int sampleRate;
       
       public:
       AudioMedia(const string& path, double sz, int rate) : MediaFile(path, sz), sampleRate(rate) {}

       void display() const override
       {
              MediaFile::display();
              cout << "sample rate: " << sampleRate << " hz" << endl;
       }
};

class VideoFile : public VisualMedia, public AudioMedia
{
       public:
       VideoFile(const string& path, double sz, const string& res, int rate) : MediaFile(path, sz), VisualMedia(path, sz, res), AudioMedia(path, sz, rate) {}

       void play() override
       {
              cout << "playing video file: " << filePath << endl;
       }

       void display() const override
       {
              VisualMedia::display();
              cout << "sample rate: " << sampleRate << " hz" << endl;
       }
};

class ImageFile : public VisualMedia
{
       public:
       ImageFile(const string& path, double sz, const string& res) : MediaFile(path, sz), VisualMedia(path, sz, res) {}

       void play() override
       {
              cout << "cannot play image file: " << filePath << endl;
       }

       void display() const override
       {
              VisualMedia::display();
       }
};

class AudioFile : public AudioMedia
{
       public:
       AudioFile(const string& path, double sz, int rate) : MediaFile(path, sz), AudioMedia(path, sz, rate) {}

       void play() override
       {
              cout << "playing audio file: " << filePath << endl;
       }

       void display() const override
       {
              AudioMedia::display();
       }
};

int main()
{
       VideoFile video("video.mp4", 200.5, "1220x1020", 23100);
       ImageFile image("image.jpg", 7.2, "1300x900");
       AudioFile audio("audio.mp3", 21.0, 50000);

       vector<MediaFile*> mediaLibrary = { &video, &image, &audio };

       for (const auto& media : mediaLibrary)
       {
            media->play();
            media->stop();
            media->display();
            cout << "-------------------" << endl;
       }

       return 0;
}

