pipeline {
    agent any

    tools {
        nodejs 'Node.js'
    }

    ws('C:\\Program Files\\Jenkins\\workspace\\New_Subbu_Project_Build') { 
        stages {
            stage('Build') {
                steps {
                    sh 'npm run build'
                }
            }
        }
    }
}
