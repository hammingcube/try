# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

class Tag {
public:
	typedef unordered_map<string, string> attr_map;
private:
	string name;
	attr_map attributes;
	vector<Tag> children;
public:
	Tag(const string & n = "", 
		const attr_map & att = attr_map(),
		const vector<Tag> & subtags = vector<Tag>()) : name(n),
													   attributes(att),
													   children(subtags) {
		// Initialize anything here.
	}

	string Serialize() {
		string output = "<" + name + ">\n";
		for(auto & tag : children) {
			output += tag.Serialize() + "\n";
		}
		output += "</" + name + ">";
		return output;
	}
	// TODO: AddTag
	// TODO: AddAttributes
	// TODO: PrettyPrint

};

int main() {
	Tag html("html", Tag::attr_map(), vector<Tag>({Tag("body")}));
	cout << html.Serialize() << endl;
	return 0;
}