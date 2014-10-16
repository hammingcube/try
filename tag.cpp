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

	string beg, end;

public:
	Tag(const string & n = "", 
		const attr_map & att = attr_map(),
		const vector<Tag> & subtags = vector<Tag>()) : name(n),
													   attributes(att),
													   children(subtags) {
		// Initialize anything here.
		beg = "<" + name + ">";
		end = "</" + name + ">";
	}

	string Serialize() {

		string output = "";
		for(auto & tag : children) {
			output += tag.Serialize() + "\n";
		}
		if (name == "")
			return output;
		return beg + "\n" + output + end + "\n";


		return output;
	}
	// TODO: AddTag
	// TODO: AddAttributes
	// TODO: PrettyPrint

};

void testEmptyTag() {
	cout << Tag().Serialize() << endl;
}

void testNested() {
	Tag html("html", Tag::attr_map(), vector<Tag>({Tag("body")}));
	cout << html.Serialize() << endl;
}

int main() {
	//testEmptyTag();
	testNested();
	
	return 0;
}