#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>

using namespace dlib;
using namespace std;


int main(int argc, char** argv) try
{

    // In particular, one simple thing we can do is face clustering.  This next bit of code
    // creates a graph of connected faces and then uses the Chinese whispers graph clustering
    // algorithm to identify how many people there are and which faces belong to whom.
    std::vector<sample_pair> edges;
    edges.push_back(sample_pair(0,2));
    edges.push_back(sample_pair(1,2));
    edges.push_back(sample_pair(1,3));
    edges.push_back(sample_pair(4,5));
    edges.push_back(sample_pair(6,5));
    edges.push_back(sample_pair(5,7));
    std::vector<unsigned long> labels;
    const auto num_clusters = chinese_whispers(edges, labels);
    // This will correctly indicate that there are 4 people in the image.
    cout << "number of clusters: "<< num_clusters << endl;

    for(auto &l : labels) {
      printf(" %ld ", l);
    }
    printf("\n");
}
catch (std::exception& e)
{
    cout << e.what() << endl;
}
