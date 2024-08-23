pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                env {
                    PATH = "C:\\Users\\Dell\\AppData\\Local\\fnm_multishells\\5532_1724423284375:$PATH"
                }
                sh 'npm run build'
            }
        }
    }
}
