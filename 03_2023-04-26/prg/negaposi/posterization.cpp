#include <iostream>
#include <opencv2/opencv.hpp>
#define FILE_NAME "../fruit_image.jpg"

// ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

// 階調数
#define COLOR_MAX (255)

int main(int argc, const char *argv[]) {
    // 入力画像の読み込み (グレースケール入力)
    cv::Mat src_img = cv::imread(FILE_NAME, cv::IMREAD_GRAYSCALE);
    
    // 読み込み失敗の場合
    if (src_img.empty()) {
        fprintf(stderr, "読み込み失敗\n");
        return (-1);
    }

    // 出力画像のメモリ確保
    cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC1);

    // 画像の走査
    for (int y = 0; y < dst_img.rows; y++) {
        for (int x = 0; x < dst_img.cols; x++) {
            // 画素値の取得
            uchar s = src_img.at<uchar>(y, x);
            // ネガポジ変換
            dst_img.at<uchar>(y, x) = COLOR_MAX - s;
        }
    }

    // 入力画像の表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);

    // 出力画像の表示
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);

    // キー入力待ち (止める)
    cv::waitKey();     

    return 0;
}